/**
 * @file Fluido.cpp
 * @author Joilson, Danielson
 *  Implementa��o de m�todos da classe FLUIDO
 * 	Revis�es:
 *
 */
 //---------------------------------------------------------------------------
#pragma hdrstop
#include "Fluido.h"
#include <fstream>
using namespace std;

Fluido* Fluido :: instance = NULL ;
bool Fluido :: instanceFlag = false ;

/**
 * @brief M�todo que instancia o objeto, caso n�o exista, ou repassa o objeto
 *				"instance" caso j� exista o objeto FLUIDO
 * @return Objeto fluido atual
 */
Fluido* Fluido :: getInstance() {
	if ( ! instanceFlag ){
		Fluido :: instance = new Fluido();
		instanceFlag = true;
	}
	return Fluido :: instance;
}

/**
 * @brief Construtor
 */
Fluido::Fluido() {
	/* Vazio */
}

/**
 * @brief Destrutor
 *				Seta como falso a flag para poder criar outro objeto do in�cio
 */
Fluido::~Fluido() {
	this->instanceFlag = false;
}

/**
 * @brief Limpa os dados para zero, para que sejam setados novos valores
 */
void Fluido::Limpar() {
	BSW = 0;
	APi = 0;
	SGgas = 0;
	SGagua = 0;
	GAMA = 0;
}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void Fluido::imprimirVariaveis(ofstream& file) {
    file << "Fluid Data:\n";
    file << "BSW = " << this->BSW << "\n";
    file << "APi = " << this->APi << "/n";
    file << "SGgas = " << this->SGgas << "/n";
    file << "SGagua = " << this->SGagua << "/n";
    file << "GAMA = " << this->GAMA << "/n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
