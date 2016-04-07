//---------------------------------------------------------------------------


#pragma hdrstop

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Simulacao.h"
#pragma package(smart_init)

using namespace std;

Simulacao::Simulacao() {
}

void Simulacao::Execute() {
	ConstantesUniversais::getInstance()->Limpar();
	VariaveisAuxiliares::getInstance()->Limpar();
	EquacoesAuxiliares::getInstance()->Limpar();

	this->continuar = false;
	this->parar = false;
	this->run();
}

void Simulacao::atualizarParametros() {
	FacedeEntidades*      f = FacedeEntidades     ::getInstance();
	ConstantesUniversais* c = ConstantesUniversais::getInstance();
	VariaveisAuxiliares*  v = VariaveisAuxiliares ::getInstance();

    f->fluido->BSW = 0.5;
	f->fluido->APi = 37;
	f->fluido->SGagua = 1.01;
	f->fluido->SGgas = 0.8;
	f->fluido->GAMA = 1.21;

	f->tubing->Lcauda = 1000;
	f->tubing->E = 0.0001320000062696636;
	f->tubing->DItbg = 0.050672999387606985;
	f->tubing->DOtbg = 0.06032499927096069;
    f->tubing->peso = 4.7;

	f->casing->comprimento = 10000;
	f->casing->rugosidade = 0.0001320000062696636;
	f->casing->DIcsg = 0.1257299984805286;
	f->casing->DEcsg = 0.13969999831169844;
	f->casing->peso = 15.5;

	f->linhaPro->Psep = 310264.0576171875;

	f->valvula->Dab = 0.01904999976977706;

	f->pistao->Mplg = 4.48;
	f->pistao->EfVed = 90;
	f->pistao->Lplg = 0.45;
	f->pistao->Dplg = 0.04952999940142035;

	f->reservat->Pest   = 5004650.0;
	f->reservat->Pteste = 326877.94999999995;
	f->reservat->Qteste = 26;
	f->reservat->RGL    = 596;

	//Setando os passos de integracao
	c->step     	= 0.01;
	c->step_ 	    = 0.01;
	c->step_aft     = 0.01;
	c->_stepGas     = 0.01;
	c->_stepGas2Liq = 0.01;
	c->_stepLiq     = 0.01;

	//Setando dados iniciais e variaveis de tempo de controle
	f->tempos->Lslg      = 15.3;
	f->tempos->PcsgT     = 721853.1591796875;
	f->tempos->Ontime    = 600;
    f->tempos->Offtime   = 585;
    f->tempos->Afterflow = 60;

}

void Simulacao::run() {

	FacedeEntidades*      f = FacedeEntidades     ::getInstance();
	ConstantesUniversais* c = ConstantesUniversais::getInstance();
	VariaveisAuxiliares*  v = VariaveisAuxiliares ::getInstance();

    cout << "Simulacao: Vai entrar no while\n";

	while ( !this->Suspended ) {
		// Somente a primeira vez que estiver iniciando a simulação.
		if ( c->estagio == 0 ) {
            cout << "Estágio: iniciarSimulacao()\n";
			EquacoesAuxiliares::getInstance()->iniciarSimulacao();
		}
		else if (c->estagio == c->OFF_BUILD_UP) {
            cout << "Estágio: inicioCiclo()\n";
			EquacoesAuxiliares::getInstance()->inicioCiclo();
		}
		else if (c->estagio == c->INICIO_CICLO) {
            this->imprimirVariaveis();
            cout << "Estágio: subidaPistao()\n";
			EquacoesAuxiliares::getInstance()->subidaPistao();
		}
		else if (c->estagio == c->SUBIDA_PISTAO) {
            cout << "Estágio: producaoLiquido()\n";
			EquacoesAuxiliares::getInstance()->producaoLiquido();
		}
		else if (c->estagio == c->PRODUCAO_LIQUIDO) {
            cout << "Estágio: Controle()\n";
			EquacoesAuxiliares::getInstance()->Controle();
		}
		else if (c->estagio == c->CONTROLE) {
            cout << "Estágio: Afterflow()\n";
			EquacoesAuxiliares::getInstance()->Afterflow();
		}
		else if (c->estagio == c->AFTERFLOW) {
            cout << "Estágio: BuildUp()\n";
			EquacoesAuxiliares::getInstance()->OffBuildUp(true);
		}
		else {
			continue;
		}
		//Se a Thread tiver que terminar
		if ( this->parar ) {
			f->Limpar();
			c->Limpar();
			v->Limpar();
			EquacoesAuxiliares::getInstance()->Limpar();
			while ( !continuar )
				sleep(1);
			this->continuar = false;
		}
		//WaitForSingleObject( this->mutex , 1000 );
	}
}

//Prints every variable in the simulator into the file
void Simulacao::imprimirVariaveis() {
	FacedeEntidades*      f = FacedeEntidades     ::getInstance();
	ConstantesUniversais* c = ConstantesUniversais::getInstance();
	VariaveisAuxiliares*  v = VariaveisAuxiliares ::getInstance();

    this->file.open("DataCPlusPlusPlunger.txt");
    file << "Jojou";
    //f->imprimirVariaveis(this.file&);
    //c->imprimirVariaveis(this.file&);
    //v->imprimirVariaveis(this.file&);
    this->file.close();

}

// Inicia a simulação alterando a flag
void Simulacao::Iniciar() {
	this->parar = false;
}

// Para a simulação alterando a flag
void Simulacao::Parar() {
	this->parar = true;
}

// Continua a simulação alterando a flag
void Simulacao::Continuar() {
	this->parar = false;
	this->continuar = true;
}

// Modifica parâmetros
bool Simulacao::modParametros() {

	// Pegar variáveis
	FacedeEntidades*      f = FacedeEntidades     ::getInstance();
	ConstantesUniversais* c = ConstantesUniversais::getInstance();
	VariaveisAuxiliares*  v = VariaveisAuxiliares ::getInstance();

	// Associações
	// Tempos de abertura
	//if ( mapa->operator [](OPENNED_TIME)   != 0 ) {
	//	f->tempos->Ontime    = mapa->operator [](OPENNED_TIME);
	//}
	//if ( mapa->operator [](CLOSED_TIME)    != 0 ) {
	//	while ( c->estagio == c->AFTERFLOW &&
	//					mapa->operator [](CLOSED_TIME) < (c->_step * v->m) ) {
	//		Sleep(100);
    //}
	//	f->tempos->Offtime   = mapa->operator [](CLOSED_TIME);
	//}
	//if ( mapa->operator [](AFTERFLOW_TIME) != 0 ) {
	//	f->tempos->Afterflow = mapa->operator [](AFTERFLOW_TIME);
	//}

	//Razão Gás Líquido
	//if ( mapa->operator [](RGL) != 0 ) {
	//	f->reservat->RGL = mapa->operator [](RGL);
	//}

	// Dados do pistão
	//if ( mapa->operator [](FENCE_EFFICIENCY) != 0 ) {
	//	f->pistao->EfVed     = mapa->operator [](FENCE_EFFICIENCY);
	//}
	//if ( mapa->operator [](PLUNGER_LENGTH)   != 0 ) {
	//	f->pistao->Lplg      = mapa->operator [](PLUNGER_LENGTH);
	//}
	//if ( mapa->operator [](PLUNGER_MASS)     != 0 ) {
	//	f->pistao->Mplg      = mapa->operator [](PLUNGER_MASS);
	//}
	//if ( mapa->operator [](FALL_IN_LIQUID_VELOCITY) != 0 ) {
	//	f->pistao->Vqpl      = mapa->operator [](FALL_IN_LIQUID_VELOCITY);
	//}
	//if ( mapa->operator [](FALL_IN_GAS_VELOCITY)    != 0 ) {
	//	f->pistao->Vqpg      = mapa->operator [](FALL_IN_GAS_VELOCITY);
	//}
	//if ( mapa->operator [](PLUNGER_DIAMETER) != 0 ) {
	//	f->pistao->Dplg      = mapa->operator [](PLUNGER_DIAMETER);
	//}
	//if ( mapa->operator [](STEP_SUBIDA) != 0 ) {
	//	c->step      = mapa->operator [](STEP_SUBIDA);
	//}
	//if ( mapa->operator [](STEP_PRODUCAO) != 0 ) {
	//	c->step_      = mapa->operator [](STEP_PRODUCAO);
	//}
	//if ( mapa->operator [](STEP_AFTERFLOW) != 0 ) {
	//	c->step_aft      = mapa->operator [](STEP_AFTERFLOW);
	//}
	//if ( mapa->operator [](STEP_BUILDUPGAS) != 0 ) {
	//	c->_stepGas      = mapa->operator [](STEP_BUILDUPGAS);
	//}
	//if ( mapa->operator [](STEP_BUILDUPGASLIQ) != 0 ) {
	//	c->_stepGas2Liq      = mapa->operator [](STEP_BUILDUPGASLIQ);
	//}
	//if ( mapa->operator [](STEP_BUILDUPLIQ) != 0 ) {
	//	c->_stepLiq      = mapa->operator [](STEP_BUILDUPLIQ);
	//}

	return true;
}
/**
 * @brief Faz o pedido de alteração no estado da válvula motora.
 */
void Simulacao::altValv() {
	EquacoesAuxiliares::getInstance()->alterValvula();
}

void Simulacao::Suspend() {
	this->Suspended = true;
}

void Simulacao::Resume() {
	this->Suspended = false;
	this->continuar = true;
}
