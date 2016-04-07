/**
 * @file ConstantesUniversais.h
 * @author Equipe AUTOPOC Plunger Lift
 *  Classe para defini��o das constantes universais utilizadas no modelo
 *	matem�tico do sistema.
 * 	Revis�es:
 *
 */
//---------------------------------------------------------------------------
#ifndef ConstantesUniversaisH
#define ConstantesUniversaisH
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
/**
 * @brief Classe que define as vari�veis constantes no modelo matem�tico.
 */
class ConstantesUniversais {
public:
	/** Vaz�o m�xima do reservat�rio */
	double Qmax;
	/** Press�o pseudo cr�tica */
	double Ppc;
	/** Temperatura pseudo cr�tica */
	double Tpc;
	/** Constante universal dos gases (N.m/mol.K) */
	double R;
	/** Adotado 80F = 26,7 C na superficie e grad 1.7 F / 100 p�s */
	double Tsup;
	/** Massa molar  do ar (kg/mol) */
	double PMar;
	/** Gravidade */
	double G;
	/** Massa molar do g�s (kg/mol) */
	double PM;

	/** Passo de integra��o na subida do pist�o */
	double step;
	/** Passo de integra��o na Produ��o */
	double step_;
	/** Passo de integra��o no Afterflow */
	double step_aft;
	/** Passo de integra��o no BuildUp (Pistao no fundo) */
	double _step;
	/** Passo de integra��o no BuildUp (Queda no Gas) */
	double _stepGas;
	/** Passo de integra��o no BuildUp (Queda no L�quido) */
	double _stepLiq;
	/** Passo de integra��o na transi��o G�s L�quido no Build Up */
    double _stepGas2Liq;

	/** �rea interna do anular */
	double AIcsg;
	/** Volume interno do anular */
	double Vcsg;
	/** Raz�o de �gua no l�quido produzido */
	double FW;
	/** Densidade relativa do �leo em rela��o � �gua */
	double SGoleo;
	/** Massa espec�fica do l�quido (Kg/m3) */
	double ROliq;
	/** Massa espec�fica do g�s (Kg/m3) */
	double ROgas;
	/** Constante para g�s natural (R/mol) constante universal dos gases sobre
			massa molar do gas */
	double Rgn;
	/** �rea interna do tubing */
	double AItbg;
	/** Temperatura m�dia do anular */
	double TTcsg;
	/** K - temperatura padr�o (0�C) */
	double Tstd;
	/** Press�o padrao (Pa) */
	double Pstd;
	/** Velocidade do pist�o para ser considerada lenta */
	float Slow;
	/** Velocidade do pist�o para ser considerada rapida */
	float Fast;
	/** Chute de uma boa velocidade (n�o usada) */
	float good_velocity;

	//func�es (ainda sem funcionalidade)
	/** Fun��o para pegar a constante de inicio ciclo */
	const double getINICIO_CICLO() const ;
	/** Fun��o para pegar a constante de subida pist�o */
	const double getSUBIDA_PISTAO() const ;
	/** Fun��o para pegar a constante de produ��o */
	const double getPRODUCAO_LIQUIDO() const ;
	/** Fun��o para pegar a constante de Controle */
	const double getCONTROLE() const ;
	/** Fun��o para pegar a constante de Afterflow */
	const double getAFTERFLOW() const ;
	/** Fun��o para pegar a constante de Buildup */
	const double getOFF_BUILD_UP() const ;
	/** Fun��o para pegar a constante de Iniciar */
	const double getINICIAR() const ;
	/** Fun��o para pegar a constante do estagio atual */
	const double getEstagio() const ;

	//Vari�veis
	/** Vari�vel para representar o estagio */
	double estagio;
	/** Vari�vel para representar o iniciar */
	double INICIAR;
	/** Vari�vel para representar o inicio ciclo */
	double INICIO_CICLO;
	/** Vari�vel para representar a subida do pist�o */
	double SUBIDA_PISTAO;
	/** Vari�vel para representar a produ��o de l�quido */
	double PRODUCAO_LIQUIDO;
	/** Vari�vel para representar o est�gio de controle */
	double CONTROLE;
	/** Vari�vel para representar o afterflow */
	double AFTERFLOW;
	/** Vari�vel para representar o buildup */
	double OFF_BUILD_UP;
	/** Fun��o que pega a inst�ncia �nica da classe */
	static ConstantesUniversais* getInstance();
	/** Destrutor */
	void Limpar();
	/** Imprime as vari�veis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	/** �nica inst�ncia da classe */
	static ConstantesUniversais* instance;
	/** Flag para indicar se h� inst�ncia ativa */
	static bool instanceFlag;
	/** Construtor da classe */
	ConstantesUniversais();
	/** Fun��o de inicia��o da classe */
	void init();
};
#endif
