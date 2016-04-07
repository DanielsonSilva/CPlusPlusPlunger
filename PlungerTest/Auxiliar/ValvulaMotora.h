//---------------------------------------------------------------------------

#ifndef ValvulaMotoraH
#define ValvulaMotoraH
//---------------------------------------------------------------------------
#include<stdlib.h>
#include <fstream>
using namespace std;

class ValvulaMotora
{
public:
    static ValvulaMotora* getInstance();

    // Dados utilizados na simulação
        double Dab; /*!< Diâmetro de abertura da válvula (mm) */

    // Dados não utilizados na simulação apenas para informação

	~ValvulaMotora();
	void Limpar();
	/** Imprime as variáveis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	ValvulaMotora();
	static ValvulaMotora* instance;
    static bool instanceFlag;
};

#endif
