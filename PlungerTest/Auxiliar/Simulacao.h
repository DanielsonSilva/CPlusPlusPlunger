//---------------------------------------------------------------------------

#ifndef SimulacaoH
#define SimulacaoH
//---------------------------------------------------------------------------
#include <fstream>
#include "EquacoesAuxiliares.h"
#include "ConstantesUniversais.h"
using namespace std;

class Simulacao {
public:
	Simulacao();
	void Execute() ;
	void run();
	void Iniciar();
	void Parar();
	void Continuar();
	bool modParametros();
	void altValv();
	void Suspend();
	void Resume();
	void atualizarParametros();
	void imprimirVariaveis();

	bool Suspended;

private:
	bool parar;
	bool continuar;
	ofstream file;


};
#endif
