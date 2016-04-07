/**
 * @file Fluido.h
 * @author Joilson, Danielson
 *  Características do Fluido do sistema.
 * 	Revisões:
 *
 */
//---------------------------------------------------------------------------

#ifndef FluidoH
#define FluidoH

#include<stdlib.h>
#include <fstream>
using namespace std;
/**
 * @brief Classe com as características do fluido do sistema.
 */
class Fluido {
public:
	/** Função do Singleton para ter somente 1 objeto "fluido" */
	static Fluido* getInstance();

	// Dados utilizados na simulação
	/** Fração de água no líquido */
	int BSW;
	/** Grau API do óleo do reservatório */
	double APi;
	/** Massa específica do gás */
	double SGgas;
	/** Massa específica da água */
	double SGagua;
	/** Peso específico (Ro*g) */
	double GAMA;

		// Dados não utilizados na simulação apenas para informação

	/** Destrutor da classe */
	~Fluido();
	/** Limpa os valores das características do fluido */
	void Limpar();
	/** Imprime as variáveis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	/** Construtor privado para Singleton */
	Fluido();
	/** Única instância do objeto "fluido" */
	static Fluido* instance;
	/** Variável para checagem se o objeto já foi instanciado ou não */
	static bool instanceFlag;
};
#endif
