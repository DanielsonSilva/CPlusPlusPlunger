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

    // Dados utilizados na simulação
	double PtbgT;   /*!< Pressao no topo do tubing                    */
	double PcsgB;   /*!< Pressao na base do anular                    */
	double Hplg;    /*!< Posiçao do pistão (0 = fundo poco)           */
	double Qlres;   /*!< Vazao de liquido instantanea do reservatorio */
	double pp;      /*!< Pressão no topo da golfada                   */

	// Dados não utilizados na simulação apenas para informação
	~VariaveisSaida();
	void Limpar();
	/** Imprime as variáveis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	VariaveisSaida();

    static VariaveisSaida* instance;
    static bool instanceFlag;

};

#endif
