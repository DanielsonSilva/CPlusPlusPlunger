//---------------------------------------------------------------------------

#ifndef TubingDadosH
#define TubingDadosH

#include<stdlib.h>
#include <fstream>
using namespace std;

class TubingDados
{
public:
    static TubingDados* getInstance();

    // Dados utilizados na simula��o
	double Lcauda;  /*!< Comprimento da coluna de produ��o   */
	double E;       /*!< Rugosidade do Tubing                */
	double DItbg;   /*!< Diametro interno do Tubing (m)      */
	double DOtbg;   /*!< diametro externo do Tubing          */

    // Dados n�o utilizados na simula��o apenas para informa��o
    double peso;

	~TubingDados();
	void Limpar();
	/** Imprime as vari�veis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	TubingDados();
	static TubingDados* instance;
    static bool instanceFlag;

};

#endif
