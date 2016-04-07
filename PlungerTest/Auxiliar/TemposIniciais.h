//---------------------------------------------------------------------------

#ifndef TemposIniciaisH
#define TemposIniciaisH
//---------------------------------------------------------------------------
#include<stdlib.h>
#include <fstream>
using namespace std;

class TemposIniciais
{
public:
    static TemposIniciais* getInstance();

    // Dados utilizados na simula��o
	int Afterflow;  /*!< Tempo de afterflow (s)               */
	int Offtime;    /*!< Tempo de BuildUp                     */
	int Ontime;     /*!< Tempo de v�lvula aberta              */
	double PcsgT;   /*!< Pressao no anular na superficie (Pa) */
	double Ltbg;    /*!< Nivel de liquido no fundo da coluna  */
	double Lslg;    /*!< Comprimento da glofada (m)           */

	// Dados n�o utilizados na simula��o apenas para informa��o
	bool Controller; /*!< Deve-se utilizar o controlador      */

	~TemposIniciais();
	void Limpar();
	/** Imprime as vari�veis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	TemposIniciais();
	static TemposIniciais* instance;
    static bool instanceFlag;
};

#endif
