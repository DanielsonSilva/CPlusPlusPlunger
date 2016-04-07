/**
 * @file LinhaProducao.h
 * @author Joilson, Danielson
 *  Características da linha de produção do sistema.
 * 	Revisões:
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

	// Dados utilizados na simulação
	double Psep;    /*!< Pressao no separador */

	// Dados não utilizados na simulação apenas para informação
	~LinhaProducao();
	void Limpar();
	/** Imprime as variáveis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	LinhaProducao();
	static LinhaProducao* instance;
	static bool instanceFlag;
};
#endif
