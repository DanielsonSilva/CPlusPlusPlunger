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

    // Dados utilizados na simulação
	double Lcauda;  /*!< Comprimento da coluna de produção   */
	double E;       /*!< Rugosidade do Tubing                */
	double DItbg;   /*!< Diametro interno do Tubing (m)      */
	double DOtbg;   /*!< diametro externo do Tubing          */

    // Dados não utilizados na simulação apenas para informação
    double peso;

	~TubingDados();
	void Limpar();
	/** Imprime as variáveis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	TubingDados();
	static TubingDados* instance;
    static bool instanceFlag;

};

#endif
