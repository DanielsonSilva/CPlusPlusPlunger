	 /**
 * @file EquacoesUtilitarias.h
 * @author Equipe AUTOPOC Plunger Lift
 *  Implementacao de funcoes que ajudam na resolucao de equacoes no modelo
 *	matematico.
 * 	Revisoes:
 *
 */
//---------------------------------------------------------------------------
#pragma hdrstop
#include "EquacoesUtilitarias.h"
//---------------------------------------------------------------------------
//#include <QTextStream>
/**
 * @brief Construtor da classe
 */
EquacoesUtilitarias::EquacoesUtilitarias() {
	/* Vazio */
}
//---------------------------------------------------------------------------
/**************************************************************************
 Vazao de gas (m3/d) p/ abert da valv motora (d") para atm. Fluxo critico
*/
/**
 * @brief
 * @param p1 Pressao montante abFS em (kPa).
 * @param p2 Pressao jusante abFs em (kPa).
 * @param d Diametro de passagem (mm).
 * @param T1 Temperatura montante abs (K).
 * @return
 */
double EquacoesUtilitarias::QSC(double p1,double p2,double d,double T1) {
	FacedeEntidades* f = FacedeEntidades::getInstance();
	double A,B;
	double temp;
	double Z1;	/* Z1 fator de compressibilidade a T1 e p1 */
	double k;   /* Cp/Cv   Adimensional */
	double Rpc; /* Pressure ratio at which gas flow becomes critical */
	double Cn;  /* Metric. Coefficient based on system of units, discharge */
							/* coefficient and standard conditions. */
	Z1 = Z(p1/ ConstantesUniversais::getInstance()->Ppc,T1/
																			ConstantesUniversais::getInstance()->Tpc);
	k = f->fluido->GAMA;
	Rpc = powl(2.0/(k+1),k/(k-1));
	Cn = 3.7915;

	A = (Cn*p1*powl(d,2))/sqrt(f->fluido->SGgas*T1*Z1);
	if ( p2/p1 < Rpc )
		B = Rpc; /* fluxo critico */
	else
		B=p2/p1; /* sub-critico   */

	temp = (k/(k-1)) * (powl(B,2/k) - powl(B,(k+1)/k));
	if ( temp < 0.0 ) {
		return 0.0;
	}
	return A*sqrt(temp);
}
//---------------------------------------------------------------------------
/**
 * @brief Funcao para calcular a viscosidade dinamica do gas pela correlacao
 *				de Lee et. al. (Transctions AIME, 1966, pg.997).
 * @param T temperatura
 * @param RO densidade do gás
 * @return
 */
double EquacoesUtilitarias:: VISGAS(double T, double RO) {
	 double Trank, PMg, aK, X, ROgcm3, ay;
	 Trank = 1.8 * T;
	 PMg = ConstantesUniversais::getInstance()->PM * 1000.0;
	 ROgcm3 = RO / 1000.0;
	 aK = ((9.4+0.02*PMg) * powl(Trank,1.5))/(209.0+19.0*PMg + Trank);
	 X  = 3.5 + 986.0/Trank + 0.01*PMg;
	 ay = 2.4 - 0.2*X;
	 return powl(10,-7) * aK * expl(powl(X*ROgcm3, ay));
}
//---------------------------------------------------------------------------
/**
 * @brief Calcula a viscosidade dinâmica de uma mistura óleo/água.
 * É considerada a viscosidade do óleo morto pela correlação de Beal e
 * a viscosidade da água pela correlação de Van Wingen. Não é considerado
 * gás em solução.
 * @param T Temperatura
 * @return Viscosidade dinâmica da mistura em uma dada temperatura.
 */
double EquacoesUtilitarias::VISC (double T) {
	double TF, APi, VISCw, a, b, c, VISCo;

	TF = (T-273.15)*9.0/5 + 32.0;
	VISCw = expl(1.003-1.479*powl(10,-2)*TF + 1.982*powl(10,-5)*powl(TF,2));
	APi = 141.5/ ConstantesUniversais::getInstance()->SGoleo - 131.5;
	a = 0.32 + (1.8*powl(10,7.0f))/powl(APi,4.53);
	b = 360.0/(TF + 200.0);
	c = powl(10,(0.43 + 8.33/APi));
	VISCo = a * powl(b, c);
	return (VISCo*(1.0 - ConstantesUniversais::getInstance()->FW) +
											VISCw * ConstantesUniversais::getInstance()->FW ) * 0.001;
}
//---------------------------------------------------------------------------
/**
 * @brief Calcula a temperatura devido ao gradiente geotérmico.
 * @param H (m)
 * @return T em °K
*/
double EquacoesUtilitarias::TEMP(double H){
	double Tsup,GRADT;

	Tsup = 299.8167;
	GRADT = 0.03098571;
	return  Tsup + GRADT*H;
}
//---------------------------------------------------------------------------
/**
 * @brief Calcula o fator de Fricção de Darcy-Weisbach por Colebrook.
 * @param REY Número de Reynolds.
 * @param E  (mm)
 * @param DH  (mm)
 * @return
 */
double EquacoesUtilitarias::FRIC(double REY,double E,double DH){
	double ED;
	double A,B,X,Y,YPRIM;
	ED = E/DH;
	//CALCULO PARA O REGIME LAMINAR
	if ( REY <= 2100.0 )
		return 64.0 / REY;
	//CALCULO PARA O REGIME TURBULENTO
	else
		if ( ED > 0.05 )
			return (1.0/powl((4.0*log10(0.27*ED)),2) + 0.67*powl(ED,1.73))*4.0;
		else {
			A = ED / 3.7;
			B = 2.51 / REY;
			X = (-2.0) * log10(A + powl(10,-12));
			Loop:
				Y = X + 2.0*log10(A + B*X);
				if ( fabs(Y) <= powl(10,-6) )
					return 1.0 / powl(X,2);
				YPRIM = 1.0 + (0.43429448*2.0*B) / (A + B*X);
				X = X - Y / YPRIM;
				goto Loop;
		}
}
//---------------------------------------------------------------------------
/**
 * @brief Calcula o fator de compressibilidade Z pelo método de Dranchuk,
 *				Purvis e Robinson.
 * @param Pr
 * @param Tr
 * @return
 */
double EquacoesUtilitarias::Z(double Pr,double Tr) {
	double Tr3, Z, RR, RR2, RR4, RR5, A, B, C, D, A8, AUX, FZ, DFDZ, DELTAZ;
	int K;
	Tr3 = powl(Tr,3);
	Z = 1.0;
	//return 0.9;
	for ( int K = 1; K < 51; K++ ) {
		RR = (0.27 * Pr) / (Z * Tr);
		RR2 = powl(RR,2);
		RR4 = powl(RR,4);
		RR5 = powl(RR,5);
		A = 0.31506237 - 1.0467099 / Tr - 0.57832729 / Tr3;
		B = 0.53530771 - 0.61232032 / Tr;
		C = 0.61232032 * 0.10488813 /Tr;
		D = 0.68157001 / Tr3;
		A8 = 0.68446549;
		AUX = (1+A8*RR2)*expl(-A8*RR2);
		FZ = 1 + A*RR + B*RR2 + C*RR5 + D*RR2*AUX - Z;
		DFDZ = (-A)*RR/Z -2*B*RR2/Z - 5*C*RR5/Z - 2*D*(RR2/Z)*AUX -
														 2*D*(RR4/Z)*A8*expl(-A8*RR2) + D*(RR4/Z)*AUX*2*A8-1;
		DELTAZ = FZ / DFDZ;
		if( !(fabs(DELTAZ) > 0.001) ) {
			return Z;
		}
		else {
			Z = Z - DELTAZ;
		}
	}
	return Z;
}
//---------------------------------------------------------------------------
/**
 * @brief Calcula a pressão na base de uma coluna de gás de comprimento h,
 *				levando em conta a hidrostática.
 * @param P1 Pressão acima da variavel do PONTO2.
 * @param T1
 * @param T2
 * @param H
 * @return
 */
double EquacoesUtilitarias::GASOSTB(double P1,double T1,double T2,double H) {
	double TT, P2, FP2, dP, dFP2dP2, DELTA;
	int k;
	ConstantesUniversais* c = ConstantesUniversais::getInstance();

	TT = (T1+T2)/2.0;
	k = 1;
	P2 = P1 * expl(c->PM*c->G*H/(c->R*TT));
	Loop:
		FP2 = P2 - P1*EXPOB(P1,P2,TT,H);
		dP = 1.0;
		dFP2dP2 = 1.0 - P1*(EXPOB(P1,P2+dP,TT,H)-EXPOB(P1,P2-dP,TT,H))/(2*dP);
		DELTA = FP2 / dFP2dP2;
		P2 = P2 - DELTA;
		if ( fabs(DELTA) > 1.0 ) {
			k = k + 1;
			if ( k > 50 ) {
				return 0.0;//Sub-rotina GASOSTB nao convergiu apos 50iteracoes
			}
			goto Loop;
		}
	return P2;
}
//---------------------------------------------------------------------------
/**
 * @brief
 * @param P1
 * @param P2
 * @param TT
 * @param H
 * @return
 */
double EquacoesUtilitarias::EXPOB(double P1,double P2,double TT,double H) {
	ConstantesUniversais* c = ConstantesUniversais::getInstance();
	double PP;
	PP = (P1+P2)/2.0;
	return expl(c->PM*c->G*H/ (Z(PP/c->Ppc, TT/c->Tpc) * c->R * TT));
}
//---------------------------------------------------------------------------
/**************************************************************************
		 Calcula a pressao no topo de uma coluna de gas de
		 comprimento h, levando em conta a hidrostatica.(PONTO 1 acima do PONTO2)
*/
/**
 * @brief Calcula a pressao no topo de uma coluna de gas levando em conta a
 *				hidrostatica.
 * @param P2 Pressao abaixo do Ponto1.
 * @param T2
 * @param T1
 * @param H
 * @return
 */
double EquacoesUtilitarias::GASOSTT(double P2,double T2,double T1,double H) {
	double TT, P1, PP, FP1, dP, dFP1dP1, DELTA;
	ConstantesUniversais* c = ConstantesUniversais::getInstance();
	int k;

	TT= (T1+T2)/2.0;
	k = 1;
	P1 = P2 / expl(c->PM*c->G*H/(c->R*TT));

	Loop:
		PP = (P1+P2)/2;
		FP1 = P1 - P2/expl(c->PM*c->G*H/(Z(PP/c->Ppc,TT/c->Tpc)*c->R*TT));
		dP = 1.0;
		dFP1dP1 = 1 - P2*(EXPOT(P1+dP,P2,TT,H)-EXPOT(P1-dP,P2,TT,H))/(2*dP);
		DELTA = FP1 / dFP1dP1;
		P1 = P1 - DELTA;
		if ( fabs(DELTA) > 1.0) {
			k = k+1;
			if ( k > 50 ) {
				return 0.0; //Sub-rotina GASOSTT nao convergiu apos 50 iteracoes
			}
			goto Loop;
		}
	return P1;
}
//---------------------------------------------------------------------------
/**
 * @brief
 * @param P1
 * @param P2
 * @param TT
 * @param H
 * @return
 */
double EquacoesUtilitarias::EXPOT(double P1,double P2,double TT,double H) {
	ConstantesUniversais* c = ConstantesUniversais::getInstance();
	double PP;
	PP = (P1+P2) / 2.0;
	return expl((-c->PM)*c->G*H/(Z(PP/c->Ppc,TT/c->Tpc)*c->R*TT));
}
//---------------------------------------------------------------------------
/**************************************************************************
			Calcula a pressao no topo de uma coluna de gas de
			comprimento h, levando em conta a hidrostatica e a friccao,
			entrada: P2, T2, T1, H, V, D(diam hidr.) (PONTO 1 acima do PONTO2)
			saida  : P1
*/
/**
 * @brief Calcula a pressao no topo de uma coluna de gas levando em conta a
 *				hidrostatica e a friccao.
 * @param P2 Pressao abaixo do Ponto1
 * @param T2
 * @param T1
 * @param H Comprimento da coluna de gas.
 * @param VV
 * @param D
 * @return
 */
double EquacoesUtilitarias::GASOSTF(double P2, double T2, double T1, double H,
					double VV,double D) {
	double TT, P1, FP1, dP, dFP1dP1, DELTA;
	ConstantesUniversais* c = ConstantesUniversais::getInstance();
	int k;

	TT = (T1+T2)/2.0;
	k = 1;
	P1 = P2 / expl(c->PM*c->G*H/(c->R*TT));
	Loop:
		FP1 = Gas2f(P1,P2,TT,H,VV,D);
		dP = 1.0;
		dFP1dP1 = (Gas2f(P1+dP,P2,TT,H,VV,D)-Gas2f(P1-dP,P2,TT,H,VV,D))/(2*dP);
		DELTA = FP1 / dFP1dP1;
		P1 = P1 - DELTA;
		if ( fabs(DELTA) > 1.0) {
			k = k+1;
			if ( k > 50 ) {
				return 0.0;//Sub-rotina GASOSTF nao convergiu apos 50iteracoes"
			}
			goto Loop;
		}
	return P1;
}
//---------------------------------------------------------------------------
/**
 * @brief
 * @param P1
 * @param P2
 * @param TT
 * @param H
 * @param VV
 * @param D
 * @return
 */
double EquacoesUtilitarias::Gas2f(double P1, double P2, double TT, double H,
					double VV, double D) {
	FacedeEntidades* f = FacedeEntidades::getInstance();
	ConstantesUniversais* c = ConstantesUniversais::getInstance();
	double PP, ZZ, RRO, VVISCg, RReyg, FF;
	PP  = (P1 + P2)/2.0;
	ZZ  = Z(PP/c->Ppc,TT/c->Tpc);
	RRO = PP*c->PM / (ZZ*TT*c->R);
	VVISCg = VISGAS(TT, RRO);
	RReyg  = RRO*fabs(VV) * D/VVISCg;
	FF     = FRIC(RReyg, f->tubing->E, D);
	return P1- P2/expl((c->PM*H/(ZZ*c->R*TT))*(c->G+FF*fabs(VV)*VV/(2.0*D)));
}
//---------------------------------------------------------------------------
/**
 * @brief Realiza o controle fuzzy do sistema (ainda nao implementado)
 * @param difference
 * @return
 */
double EquacoesUtilitarias::fuzzy_control(float difference){
	/*** VAZIO **/
	return difference;
}
#pragma package(smart_init)
