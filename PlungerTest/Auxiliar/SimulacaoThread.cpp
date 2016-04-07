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

// M�todo de inicio da simulacao
void SimulacaoThread::Execute() {
	this->simulacao->Suspended = false;
}

// M�todo para pausar a simulacao setando suspended da simulacao para true
void SimulacaoThread::pausarSimulacao(){
	this->simulacao->Suspend();
	this->setPausado();
}

// M�todo para saber se a simula��o est� pausada
bool SimulacaoThread::getPausado () {
	return pausado;
}

// M�todo para setar o pausado como true
void SimulacaoThread::setPausado () {
	this->pausado = true;
}

// M�todo para setar o pausado como false
void SimulacaoThread::continuarSimulacao () {
	this->pausado = false;
	this->simulacao->Resume();
}

int SimulacaoThread::pararSimulacao() {
	//Parando simulacao
	this->simulacao->Parar();

	return 1;
}

//Inicia simula��o depois da simula��o parada
void SimulacaoThread::iniciarSimulacao() {
    cout << "Chegou em iniciarSimulacao\n";
	this->pausado = false;
	this->simulacao->Resume();
	this->simulacao->Iniciar();
   	this->simulacao->Execute();

}
