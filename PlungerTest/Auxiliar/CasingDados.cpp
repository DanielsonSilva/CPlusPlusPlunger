/**
 * @file CasingDados.cpp
 * @author Joilson, Danielson
 *  Implementação da interface para o Casing do sistema.
 * 	Revisões:
 *
 */
//---------------------------------------------------------------------------
#pragma hdrstop
#include "CasingDados.h"
#include <fstream>
using namespace std;
// Instância única da classe é nula
CasingDados* CasingDados :: instance = NULL ;
// Informa que a classe ainda não foi iniciada
bool CasingDados :: instanceFlag = false ;
/**
 * @brief Pega a instância do objeto.
 *	Se caso a instância já foi criada, só repassa, senão, cria a instância.
 * @return O objeto único CasingDados.
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
 *				Informa para o flag da instância que não há objeto precisando criar
 *				outro quando for pegar a instância da classe.
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
