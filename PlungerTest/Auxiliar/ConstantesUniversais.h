/**
 * @file ConstantesUniversais.h
 * @author Equipe AUTOPOC Plunger Lift
 *  Classe para definição das constantes universais utilizadas no modelo
 *	matemático do sistema.
 * 	Revisões:
 *
 */
//---------------------------------------------------------------------------
#ifndef ConstantesUniversaisH
#define ConstantesUniversaisH
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
/**
 * @brief Classe que define as variáveis constantes no modelo matemático.
 */
class ConstantesUniversais {
public:
	/** Vazão máxima do reservatório */
	double Qmax;
	/** Pressão pseudo crítica */
	double Ppc;
	/** Temperatura pseudo crítica */
	double Tpc;
	/** Constante universal dos gases (N.m/mol.K) */
	double R;
	/** Adotado 80F = 26,7 C na superficie e grad 1.7 F / 100 pés */
	double Tsup;
	/** Massa molar  do ar (kg/mol) */
	double PMar;
	/** Gravidade */
	double G;
	/** Massa molar do gás (kg/mol) */
	double PM;

	/** Passo de integração na subida do pistão */
	double step;
	/** Passo de integração na Produção */
	double step_;
	/** Passo de integração no Afterflow */
	double step_aft;
	/** Passo de integração no BuildUp (Pistao no fundo) */
	double _step;
	/** Passo de integração no BuildUp (Queda no Gas) */
	double _stepGas;
	/** Passo de integração no BuildUp (Queda no Líquido) */
	double _stepLiq;
	/** Passo de integração na transição Gás Líquido no Build Up */
    double _stepGas2Liq;

	/** Área interna do anular */
	double AIcsg;
	/** Volume interno do anular */
	double Vcsg;
	/** Razão de água no líquido produzido */
	double FW;
	/** Densidade relativa do óleo em relação à água */
	double SGoleo;
	/** Massa específica do líquido (Kg/m3) */
	double ROliq;
	/** Massa específica do gás (Kg/m3) */
	double ROgas;
	/** Constante para gás natural (R/mol) constante universal dos gases sobre
			massa molar do gas */
	double Rgn;
	/** Área interna do tubing */
	double AItbg;
	/** Temperatura média do anular */
	double TTcsg;
	/** K - temperatura padrão (0°C) */
	double Tstd;
	/** Pressão padrao (Pa) */
	double Pstd;
	/** Velocidade do pistão para ser considerada lenta */
	float Slow;
	/** Velocidade do pistão para ser considerada rapida */
	float Fast;
	/** Chute de uma boa velocidade (não usada) */
	float good_velocity;

	//funcões (ainda sem funcionalidade)
	/** Função para pegar a constante de inicio ciclo */
	const double getINICIO_CICLO() const ;
	/** Função para pegar a constante de subida pistão */
	const double getSUBIDA_PISTAO() const ;
	/** Função para pegar a constante de produção */
	const double getPRODUCAO_LIQUIDO() const ;
	/** Função para pegar a constante de Controle */
	const double getCONTROLE() const ;
	/** Função para pegar a constante de Afterflow */
	const double getAFTERFLOW() const ;
	/** Função para pegar a constante de Buildup */
	const double getOFF_BUILD_UP() const ;
	/** Função para pegar a constante de Iniciar */
	const double getINICIAR() const ;
	/** Função para pegar a constante do estagio atual */
	const double getEstagio() const ;

	//Variáveis
	/** Variável para representar o estagio */
	double estagio;
	/** Variável para representar o iniciar */
	double INICIAR;
	/** Variável para representar o inicio ciclo */
	double INICIO_CICLO;
	/** Variável para representar a subida do pistão */
	double SUBIDA_PISTAO;
	/** Variável para representar a produção de líquido */
	double PRODUCAO_LIQUIDO;
	/** Variável para representar o estágio de controle */
	double CONTROLE;
	/** Variável para representar o afterflow */
	double AFTERFLOW;
	/** Variável para representar o buildup */
	double OFF_BUILD_UP;
	/** Função que pega a instância única da classe */
	static ConstantesUniversais* getInstance();
	/** Destrutor */
	void Limpar();
	/** Imprime as variáveis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	/** Única instância da classe */
	static ConstantesUniversais* instance;
	/** Flag para indicar se há instância ativa */
	static bool instanceFlag;
	/** Construtor da classe */
	ConstantesUniversais();
	/** Função de iniciação da classe */
	void init();
};
#endif
