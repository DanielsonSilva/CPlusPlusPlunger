/**
 * @file EquacoesUtilitarias.h
 * @author Equipe AUTOPOC Plunger Lift
 *  Interface de funcoes que ajudam na resolucao de equacoes no modelo
 *	matematico.
 * 	Revisoes:
 *
 */
//---------------------------------------------------------------------------
#ifndef EquacoesUtilitariasH
#define EquacoesUtilitariasH
//---------------------------------------------------------------------------
#include <math.h>
#include <cmath>
using std :: log10 ;
#include "ConstantesUniversais.h"
#include "FacedeEntidades.h"
/**
 * @brief Objeto que armazena funcoes para auxiliar nos calculos matematicos
 *				do modelo.
 */
class EquacoesUtilitarias {
	public:
		/** Construtor da classe */
		EquacoesUtilitarias();
		/**  */
		static double QSC(double p1,double p2,double d,double T1);
		/**  */
		static double VISGAS(double T, double RO);
		/**  */
		static double VISC (double T);
		/**  */
		static double TEMP(double H);
		/**  */
		static double FRIC(double REY,double E,double DH);
		/**  */
		static double Z(double Pr,double Tr);
		/**  */
		static double GASOSTB(double P1,double T1,double T2,double H);
		/**  */
		static double EXPOB(double P1,double P2,double TT,double H);
		/** Calcula a pressao no topo de uma coluna de gas levando em conta a
				hidrostatica. */
		static double GASOSTT(double P2,double T2,double T1,double H);
		/**  */
		static double EXPOT(double P1,double P2,double TT,double H);
		/** Calcula a pressao no topo de uma coluna de gas levando em conta a
				hidrostatica e a friccao. */
		static double GASOSTF(double P2,double T2,double T1,double H,double VV,double D);
		/**  */
		static double Gas2f(double P1,double P2,double TT,double H,double VV,double D);
		/** Realiza o controle fuzzy do sistema (ainda nao implementado) */
		static double fuzzy_control(float difference);
};
#endif
