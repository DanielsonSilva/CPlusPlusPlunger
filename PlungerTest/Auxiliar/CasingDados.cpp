/**
 * @file CasingDados.cpp
 * @author Joilson, Danielson
 *  Implementa��o da interface para o Casing do sistema.
 * 	Revis�es:
 *
 */
//---------------------------------------------------------------------------
#pragma hdrstop
#include "CasingDados.h"
#include <fstream>
using namespace std;
// Inst�ncia �nica da classe � nula
CasingDados* CasingDados :: instance = NULL ;
// Informa que a classe ainda n�o foi iniciada
bool CasingDados :: instanceFlag = false ;
/**
 * @brief Pega a inst�ncia do objeto.
 *	Se caso a inst�ncia j� foi criada, s� repassa, sen�o, cria a inst�ncia.
 * @return O objeto �nico CasingDados.
 */
CasingDados* CasingDados :: getInstance() {
	if ( ! instanceFlag ){
		CasingDados :: instance = new CasingDados();
		instanceFlag = true;
	}
	return CasingDados :: instance;
}
//---------------------------------------------------------------------------
/**
 * @brief Construtor.
 */
CasingDados::CasingDados() {
// Vazio
}
//---------------------------------------------------------------------------
/**
 * @brief Destrutor.
 *				Informa para o flag da inst�ncia que n�o h� objeto precisando criar
 *				outro quando for pegar a inst�ncia da classe.
 */
CasingDados::~CasingDados() {
	this->instanceFlag = false;
}
//---------------------------------------------------------------------------
/**
 * @brief Reinicia os dados do objeto.
 */
void CasingDados::Limpar() {
	DIcsg = 0;
	comprimento = 0;
	rugosidade = 0;
	DEcsg = 0;
	peso = 0;
}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void CasingDados::imprimirVariaveis(ofstream& file) {
    file << "Casing Data:\n";
    file << "DIcsg = " << this->DIcsg << "\n";
    file << "comprimento = " << this->comprimento << "/n";
    file << "rugosidade = " << this->rugosidade << "/n";
    file << "DEcsg = " << this->DEcsg << "/n";
    file << "peso = " << this->peso << "/n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
