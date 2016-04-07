/**
 * @file FacedeEntidades.h
 * @author Equipe AUTOPOC Plunger Lift
 *  Implementacao do objeto que faz parte do padrao Facade para acessar as
 *	entidades do sistema.
 * 	Revisoes:
 *
 */
//---------------------------------------------------------------------------
#pragma hdrstop
#include <fstream>
#include "FacedeEntidades.h"
using namespace std;
//---------------------------------------------------------------------------
// Faz que a instancia seja nula no inicio
FacedeEntidades* FacedeEntidades :: instance = NULL ;
// Seta que a instancia da classe nao foi criada ainda
bool FacedeEntidades :: instanceFlag = false ;
/**
 * @brief Funcao para pegar a unica instancia da classe.
 */
FacedeEntidades* FacedeEntidades :: getInstance() {
        if ( ! instanceFlag ){
				FacedeEntidades :: instance = new FacedeEntidades();
                instanceFlag = true;
        }
        return FacedeEntidades :: instance;
}
//---------------------------------------------------------------------------
/**
 * @brief Destrutor da classe.
 *				Deleta todos os objetos do sistema.
 */
FacedeEntidades::~FacedeEntidades() {
	this->instanceFlag = false;
	delete tubing  ;
	delete casing  ;
	delete valvula ;
	delete linhaPro;
	delete reservat;
	delete pistao  ;
	delete fluido  ;
	delete tempos  ;
	delete varSaida;
}
//---------------------------------------------------------------------------
/**
 * @brief Reseta as variaveis do sistema.
 */
void FacedeEntidades::Limpar() {
	tubing->Limpar()  ;
	casing->Limpar()  ;
	valvula->Limpar() ;
	linhaPro->Limpar();
	reservat->Limpar();
	pistao->Limpar()  ;
	fluido->Limpar()  ;
	tempos->Limpar()  ;
	varSaida->Limpar();
}
//---------------------------------------------------------------------------
/**
 * @brief Prints all the class variables
 * @param file File that the variables will be printed
 */
void FacedeEntidades::imprimirVariaveis(ofstream& file) {
    tubing->imprimirVariaveis(file)  ;
	casing->imprimirVariaveis(file)  ;
	valvula->imprimirVariaveis(file) ;
	linhaPro->imprimirVariaveis(file);
	reservat->imprimirVariaveis(file);
	pistao->imprimirVariaveis(file)  ;
	fluido->imprimirVariaveis(file)  ;
	tempos->imprimirVariaveis(file)  ;
	varSaida->imprimirVariaveis(file);
}
//---------------------------------------------------------------------------
/**
 * @brief Construtor da classe.
 *				Cria todos os objetos necessarios para os calculos do modelo
 *				matematico.
 */
FacedeEntidades::FacedeEntidades() {
	this->tubing = TubingDados::getInstance();
    this->casing = CasingDados::getInstance();
    this->valvula = ValvulaMotora::getInstance();
    this->linhaPro = LinhaProducao::getInstance();
    this->reservat = Reservatorio::getInstance();
    this->pistao = Pistao::getInstance();
    this->fluido = Fluido::getInstance();
    this->tempos = TemposIniciais::getInstance();
    this->varSaida = VariaveisSaida::getInstance();
}
#pragma package(smart_init)
