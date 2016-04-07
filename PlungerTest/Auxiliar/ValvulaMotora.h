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

    // Dados utilizados na simula��o
        double Dab; /*!< Di�metro de abertura da v�lvula (mm) */

    // Dados n�o utilizados na simula��o apenas para informa��o

	~ValvulaMotora();
	void Limpar();
	/** Imprime as vari�veis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	ValvulaMotora();
	static ValvulaMotora* instance;
    static bool instanceFlag;
};

#endif
