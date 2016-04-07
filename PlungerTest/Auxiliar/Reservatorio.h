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

    // Dados utilizados na simulação
	double Pest;    /*!< Pressao Estatica    */
	double Qteste;  /*!< Vazao de Teste???   */
	double Pteste;  /*!< Pressao de Teste??? */
	int RGL;        /*!< Razao gas-liquido de producao (m3 std / m3) */

	// Dados não utilizados na simulação apenas para informação


	~Reservatorio();
	void Limpar();
	/** Imprime as variáveis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	Reservatorio();
	static Reservatorio* instance;
    static bool instanceFlag;
};

#endif
