/**
 * @file LinhaProducao.h
 * @author Joilson, Danielson
 *  Caracter�sticas da linha de produ��o do sistema.
 * 	Revis�es:
 *
 */
//---------------------------------------------------------------------------
#ifndef LinhaProducaoH
#define LinhaProducaoH

#include<stdlib.h>
#include <fstream>
using namespace std;

class LinhaProducao {
public:
	static LinhaProducao* getInstance();

	// Dados utilizados na simula��o
	double Psep;    /*!< Pressao no separador */

	// Dados n�o utilizados na simula��o apenas para informa��o
	~LinhaProducao();
	void Limpar();
	/** Imprime as vari�veis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	LinhaProducao();
	static LinhaProducao* instance;
	static bool instanceFlag;
};
#endif
