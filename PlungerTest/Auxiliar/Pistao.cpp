//---------------------------------------------------------------------------
#pragma hdrstop
#include "Pistao.h"
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
Pistao* Pistao :: instance = NULL ;
bool Pistao :: instanceFlag = false ;

Pistao* Pistao :: getInstance() {
        if ( ! instanceFlag ){
                Pistao :: instance = new Pistao();
                instanceFlag = true;
        }
        return Pistao :: instance;
}

Pistao::Pistao()
{
}

Pistao::~Pistao()
{
	this->instanceFlag = false;
}

void Pistao::Limpar() {

	EfVed= 0;
	Mplg = 0;
	Lplg = 0;
	Vqpl = 0;
	Vqpg = 0;
	Dplg = 0;

}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void Pistao::imprimirVariaveis(ofstream& file) {
    file << "Plunger Data:\n";
    file << "EfVed = " << this->EfVed << "\n";
    file << "Mplg = " << this->Mplg << "\n";
    file << "Lplg = " << this->Lplg << "\n";
    file << "Vqpl = " << this->Vqpl << "\n";
    file << "Vqpg = " << this->Vqpg << "\n";
    file << "Dplg = " << this->Dplg << "\n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
