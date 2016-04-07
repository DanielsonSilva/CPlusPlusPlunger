/**
 * @file Fluido.h
 * @author Joilson, Danielson
 *  Caracter�sticas do Fluido do sistema.
 * 	Revis�es:
 *
 */
//---------------------------------------------------------------------------

#ifndef FluidoH
#define FluidoH

#include<stdlib.h>
#include <fstream>
using namespace std;
/**
 * @brief Classe com as caracter�sticas do fluido do sistema.
 */
class Fluido {
public:
	/** Fun��o do Singleton para ter somente 1 objeto "fluido" */
	static Fluido* getInstance();

	// Dados utilizados na simula��o
	/** Fra��o de �gua no l�quido */
	int BSW;
	/** Grau API do �leo do reservat�rio */
	double APi;
	/** Massa espec�fica do g�s */
	double SGgas;
	/** Massa espec�fica da �gua */
	double SGagua;
	/** Peso espec�fico (Ro*g) */
	double GAMA;

		// Dados n�o utilizados na simula��o apenas para informa��o

	/** Destrutor da classe */
	~Fluido();
	/** Limpa os valores das caracter�sticas do fluido */
	void Limpar();
	/** Imprime as vari�veis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	/** Construtor privado para Singleton */
	Fluido();
	/** �nica inst�ncia do objeto "fluido" */
	static Fluido* instance;
	/** Vari�vel para checagem se o objeto j� foi instanciado ou n�o */
	static bool instanceFlag;
};
#endif
