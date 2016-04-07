//---------------------------------------------------------------------------

#ifndef PistaoH
#define PistaoH
//---------------------------------------------------------------------------

#include<stdlib.h>
#include <fstream>
using namespace std;

class Pistao
{
public:
    static Pistao* getInstance();

	// Dados utilizados na simula��o
	float EfVed;   /*!< Eficiencia de Vedacao ao Gas (%)      */
	double Mplg;   /*!< Massa do pistao (kg)                  */
	float Lplg;    /*!< Comprimento do pistao (m)                */
	double Vqpl;   /*!< Velocidade de Queda no Liquido (m/s)  */
	double Vqpg;   /*!< Velocidade de Queda no Gas (m/s)      */
	double Dplg;   /*!< Di�metro do pist�o (m)                    */

	// Dados n�o utilizados na simula��o apenas para informa��o
	~Pistao();
	void Limpar();
	/** Imprime as vari�veis da classe */
    void imprimirVariaveis(ofstream& file);

private:
	Pistao();
	static Pistao* instance;
    static bool instanceFlag;
};
#endif
