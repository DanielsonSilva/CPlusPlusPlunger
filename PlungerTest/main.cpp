#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "Auxiliar/Simulacao.h"
#include "Auxiliar/Pistao.h"
#include "Auxiliar/SimulacaoThread.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//printf("Printando\n");
	cout << "Pressione uma tecla...\n";
	//Criar a simulacao, setar as variaveis normais e verificar valores
	cout << "Comecou\n";

    Simulacao* simulador = new Simulacao();
    SimulacaoThread* thread = new SimulacaoThread(simulador,0);
    simulador->atualizarParametros();
    thread->iniciarSimulacao();

	//system("PAUSE");
	return 0;
}
