//---------------------------------------------------------------------------


#pragma hdrstop

#include "Reservatorio.h"
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------

Reservatorio* Reservatorio :: instance = NULL ;
bool Reservatorio :: instanceFlag = false ;

Reservatorio* Reservatorio :: getInstance() {
        if ( ! instanceFlag ){
                Reservatorio :: instance = new Reservatorio();
                instanceFlag = true;
        }
        return Reservatorio :: instance;
}

Reservatorio::Reservatorio()
{
}

Reservatorio::~Reservatorio()
{
	this->instanceFlag = false;
}

void Reservatorio::Limpar() {

	Pest = 0;
	Qteste = 0;
	Pteste = 0;
	RGL = 0;

}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void Reservatorio::imprimirVariaveis(ofstream& file) {
    file << "Reservoir Data:\n";
    file << "Pest = " << this->Pest << "\n";
    file << "Qteste = " << this->Qteste << "\n";
    file << "Pteste = " << this->Pteste << "\n";
    file << "RGL = " << this->RGL << "\n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
