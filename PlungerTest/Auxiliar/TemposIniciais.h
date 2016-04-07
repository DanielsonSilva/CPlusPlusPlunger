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

    // Dados utilizados na simulação
	int Afterflow;  /*!< Tempo de afterflow (s)               */
	int Offtime;    /*!< Tempo de BuildUp                     */
	int Ontime;     /*!< Tempo de válvula aberta              */
	double PcsgT;   /*!< Pressao no anular na superficie (Pa) */
	double Ltbg;    /*!< Nivel de liquido no fundo da coluna  */
	double Lslg;    /*!< Comprimento da glofada (m)           */

	// Dados não utilizados na simulação apenas para informação
	bool Controller; /*!< Deve-se utilizar o controlador      */

	~TemposIniciais();
	void Limpar();
	/** Imprime as variáveis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	TemposIniciais();
	static TemposIniciais* instance;
    static bool instanceFlag;
};

#endif
