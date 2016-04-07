//---------------------------------------------------------------------------

#ifndef ReservatorioH
#define ReservatorioH
//---------------------------------------------------------------------------

#include<stdlib.h>
#include <fstream>
using namespace std;

class Reservatorio
{
public:
    static Reservatorio* getInstance();

    // Dados utilizados na simula��o
	double Pest;    /*!< Pressao Estatica    */
	double Qteste;  /*!< Vazao de Teste???   */
	double Pteste;  /*!< Pressao de Teste??? */
	int RGL;        /*!< Razao gas-liquido de producao (m3 std / m3) */

	// Dados n�o utilizados na simula��o apenas para informa��o


	~Reservatorio();
	void Limpar();
	/** Imprime as vari�veis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	Reservatorio();
	static Reservatorio* instance;
    static bool instanceFlag;
};

#endif
