/**
 * @file ConstantesUniversais.cpp
 * @author Equipe AUTOPOC Plunger Lift
 *  Implementação da interface para o Casing do sistema.
 * 	Revisões:
 *
 */
//---------------------------------------------------------------------------
#pragma hdrstop
#include "ConstantesUniversais.h"
#include <fstream>
//---------------------------------------------------------------------------
#include<stdlib.h>
using namespace std;
// A instância da classe é nula
ConstantesUniversais* ConstantesUniversais :: instance = NULL ;
// Indica que a classe ainda não foi instanciada
bool ConstantesUniversais :: instanceFlag = false ;
/**
 * @brief Pega a instância única da classe.
 *	Se caso a instância ja foi criada, só repassa, senão, cria a instância.
 */
ConstantesUniversais* ConstantesUniversais :: getInstance() {
	if ( ! instanceFlag ){
		ConstantesUniversais :: instance = new ConstantesUniversais();
		instanceFlag = true;
	}
	return ConstantesUniversais :: instance;
}
//---------------------------------------------------------------------------
/**
 * @brief Reinicia as variáveis da classe para o valor default.
 */
void ConstantesUniversais::Limpar() {
	this->init();
}
//---------------------------------------------------------------------------
/**
 * @brief Construtor da classe.
 */
ConstantesUniversais::ConstantesUniversais() {
	this->init();
}
//---------------------------------------------------------------------------
/**
 * @brief Inicializa as variáveis do sistema pelo seu valor default.
 */
void ConstantesUniversais::init() {
	//Inicialização dos valores das etapas
	this->INICIAR          = 1;
	this->INICIO_CICLO     = 2;
	this->SUBIDA_PISTAO    = 3;
	this->PRODUCAO_LIQUIDO = 4;
	this->CONTROLE         = 5;
	this->AFTERFLOW        = 6;
	this->OFF_BUILD_UP     = 7;
	this->estagio          = 0;

	//Inicialização das constantes
	this->G    = 9.81;
	this->PMar = 0.02897;
	this->Tsup = 5 * (80.0-32.0)/9.0 + 273.15;
	this->R    = 8.314;
	this->Pstd = 101325;
	this->Tstd = 273.16;
	this->good_velocity = 5.0;
	this->ROgas = 0.766;
}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void ConstantesUniversais::imprimirVariaveis(ofstream& file) {
    file << "Universal Constants Data:\n";
    file << "Qmax = " << this->Qmax << "\n";
    file << "Ppc = " << this->Ppc << "\n";
    file << "Tpc = " << this->Tpc << "\n";
    file << "R = " << this->R << "\n";
    file << "Tsup = " << this->Tsup << "\n";
    file << "PMar = " << this->PMar << "\n";
    file << "G = " << this->G << "\n";
    file << "PM = " << this->PM << "\n";
    file << "step = " << this->step << "\n";
    file << "step_ = " << this->step_ << "\n";
    file << "step_aft = " << this->step_aft << "\n";
    file << "_step = " << this->_step << "\n";
    file << "_stepGas = " << this->_stepGas << "\n";
    file << "_stepLiq = " << this->_stepLiq << "\n";
    file << "_stepGas2Liq = " << this->_stepGas2Liq << "\n";
    file << "AIcsg = " << this->AIcsg << "\n";
    file << "Vcsg = " << this->Vcsg << "\n";
    file << "FW = " << this->FW << "\n";
    file << "SGoleo = " << this->SGoleo << "\n";
    file << "ROliq = " << this->ROliq << "\n";
    file << "ROgas = " << this->ROgas << "\n";
    file << "Rgn = " << this->Rgn << "\n";
    file << "AItbg = " << this->AItbg << "\n";
    file << "TTcsg = " << this->TTcsg << "\n";
    file << "Tstd = " << this->Tstd << "\n";
    file << "Pstd = " << this->Pstd << "\n";
    file << "Slow = " << this->Slow << "\n";
    file << "Fast = " << this->Fast << "\n";
    file << "good_velocity = " << this->good_velocity << "\n";
    file << "Tstd = " << this->Tstd << "\n";
    file << "Pstd = " << this->Pstd << "\n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------
/**
 * @brief Verifica o valor da variável INICIAR.
 * @return Valor da variável INICIAR.
 */
const double ConstantesUniversais :: getINICIAR() const {
		return this->INICIAR ;
}
//---------------------------------------------------------------------------
/**
 * @brief Verifica o valor da variável INICIO_CICLO.
 * @return Valor da variável INICIO_CICLO.
 */
const double ConstantesUniversais :: getINICIO_CICLO() const {
		return this->INICIO_CICLO ;
}
//---------------------------------------------------------------------------
/**
 * @brief Verifica o valor da variável SUBIDA_PISTAO.
 * @return Valor da variável SUBIDA_PISTAO.
 */
const double ConstantesUniversais :: getSUBIDA_PISTAO() const {
		return this->SUBIDA_PISTAO ;
}
//---------------------------------------------------------------------------
/**
 * @brief Verifica o valor da variável PRODUCAO_LIQUIDO.
 * @return Valor da variável PRODUCAO_LIQUIDO.
 */
const double ConstantesUniversais :: getPRODUCAO_LIQUIDO() const {
		return this->PRODUCAO_LIQUIDO ;
}
//---------------------------------------------------------------------------
/**
 * @brief Verifica o valor da variável CONTROLE.
 * @return Valor da variável CONTROLE.
 */
const double ConstantesUniversais :: getCONTROLE() const {
		return this->CONTROLE;
}
//---------------------------------------------------------------------------
/**
 * @brief Verifica o valor da variável AFTERFLOW.
 * @return Valor da variável AFTERFLOW.
 */
const double ConstantesUniversais :: getAFTERFLOW() const {
		return this->AFTERFLOW ;
}
//---------------------------------------------------------------------------
/**
 * @brief Verifica o valor da variável BUILDUP.
 * @return Valor da variável BUILDUP.
 */
const double ConstantesUniversais :: getOFF_BUILD_UP() const {
		return this->OFF_BUILD_UP ;
}
//---------------------------------------------------------------------------
/**
 * @brief Verifica o valor da variável Estagio.
 * @return Valor da variável Estagio.
 */
const double ConstantesUniversais :: getEstagio() const {
		return this->estagio ;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
