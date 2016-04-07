//---------------------------------------------------------------------------


#pragma hdrstop

#include "VariaveisSaida.h"
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------

VariaveisSaida* VariaveisSaida :: instance = NULL ;
bool VariaveisSaida :: instanceFlag = false ;

VariaveisSaida* VariaveisSaida :: getInstance() {
        if ( ! instanceFlag ){
                VariaveisSaida :: instance = new VariaveisSaida();
                instanceFlag = true;
        }
        return VariaveisSaida :: instance;
}

VariaveisSaida::VariaveisSaida()
{
}

VariaveisSaida::~VariaveisSaida()
{
	this->instanceFlag = false;
}

void VariaveisSaida::Limpar() {

	PtbgT = 0;
	PcsgB = 0;
	Hplg  = 0;
	Qlres = 0;
	pp    = 0;

}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void VariaveisSaida::imprimirVariaveis(ofstream& file) {
    file << "Output Variable Data:\n";
    file << "PtbgT = " << this->PtbgT << "\n";
    file << "PcsgB = " << this->PcsgB << "/n";
    file << "Hplg = " << this->Hplg << "/n";
    file << "Qlres = " << this->Qlres << "/n";
    file << "pp = " << this->pp << "/n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
