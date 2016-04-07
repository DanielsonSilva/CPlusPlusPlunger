//---------------------------------------------------------------------------
#pragma hdrstop
#include "SimulacaoThread.h"
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)

SimulacaoThread::SimulacaoThread(Simulacao* sm,	bool CreateSuspended) {
	this->simulacao = sm;
	this->pausado = CreateSuspended;
}

// Método de inicio da simulacao
void SimulacaoThread::Execute() {
	this->simulacao->Suspended = false;
}

// Método para pausar a simulacao setando suspended da simulacao para true
void SimulacaoThread::pausarSimulacao(){
	this->simulacao->Suspend();
	this->setPausado();
}

// Método para saber se a simulação está pausada
bool SimulacaoThread::getPausado () {
	return pausado;
}

// Método para setar o pausado como true
void SimulacaoThread::setPausado () {
	this->pausado = true;
}

// Método para setar o pausado como false
void SimulacaoThread::continuarSimulacao () {
	this->pausado = false;
	this->simulacao->Resume();
}

int SimulacaoThread::pararSimulacao() {
	//Parando simulacao
	this->simulacao->Parar();

	return 1;
}

//Inicia simulação depois da simulação parada
void SimulacaoThread::iniciarSimulacao() {
    cout << "Chegou em iniciarSimulacao\n";
	this->pausado = false;
	this->simulacao->Resume();
	this->simulacao->Iniciar();
   	this->simulacao->Execute();

}
