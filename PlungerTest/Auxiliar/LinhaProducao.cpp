/**
 * @file LinhaProducao.cpp
 * @author Joilson, Danielson, Erick
 *  Implementação dos métodos da Linha de produção do sistema.
 * 	Revisões:
 *
 */
//---------------------------------------------------------------------------
#pragma hdrstop
#include "LinhaProducao.h"
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------

LinhaProducao* LinhaProducao :: instance = NULL ;
bool LinhaProducao :: instanceFlag = false ;

LinhaProducao* LinhaProducao :: getInstance() {
	if ( ! instanceFlag ){
		LinhaProducao :: instance = new LinhaProducao();
		instanceFlag = true;
	}
	return LinhaProducao :: instance;
}

LinhaProducao::LinhaProducao() {
	/* Vazio */
}

LinhaProducao::~LinhaProducao() {
	this->instanceFlag = false;
}

void LinhaProducao::Limpar() {
	Psep = 0;
}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void LinhaProducao::imprimirVariaveis(ofstream& file) {
    file << "Production Line Data:\n";
    file << "Psep = " << this->Psep << "\n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
