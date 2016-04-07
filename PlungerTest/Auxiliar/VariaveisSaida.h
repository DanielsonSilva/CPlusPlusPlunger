//---------------------------------------------------------------------------

#ifndef VariaveisSaidaH
#define VariaveisSaidaH
//---------------------------------------------------------------------------

#include<stdlib.h>
#include <fstream>
using namespace std;

class VariaveisSaida
{
public:
    static VariaveisSaida* getInstance();

    // Dados utilizados na simula��o
	double PtbgT;   /*!< Pressao no topo do tubing                    */
	double PcsgB;   /*!< Pressao na base do anular                    */
	double Hplg;    /*!< Posi�ao do pist�o (0 = fundo poco)           */
	double Qlres;   /*!< Vazao de liquido instantanea do reservatorio */
	double pp;      /*!< Press�o no topo da golfada                   */

	// Dados n�o utilizados na simula��o apenas para informa��o
	~VariaveisSaida();
	void Limpar();
	/** Imprime as vari�veis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	VariaveisSaida();

    static VariaveisSaida* instance;
    static bool instanceFlag;

};

#endif
