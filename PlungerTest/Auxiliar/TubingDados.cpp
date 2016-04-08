//---------------------------------------------------------------------------
#pragma hdrstop

#include "TubingDados.h"
//---------------------------------------------------------------------------
#include "TubingDados.h"
#include <fstream>
using namespace std;

TubingDados* TubingDados :: instance = NULL ;
bool TubingDados :: instanceFlag = false ;

TubingDados* TubingDados :: getInstance() {
        if ( ! instanceFlag ){
                TubingDados :: instance = new TubingDados();
                instanceFlag = true;
        }
        return TubingDados :: instance;
}

TubingDados::TubingDados()
{

}

TubingDados::~TubingDados()
{
	this->instanceFlag = false;
}

void TubingDados::Limpar() {

	Lcauda = 0;
	E      = 0;
	DItbg  = 0;
	DOtbg  = 0;

}
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void TubingDados::imprimirVariaveis(ofstream& file) {
    file << "Tubing Data:\n";
    file << "Lcauda = " << this->Lcauda << "\n";
    file << "E = " << this->E << "\n";
    file << "DItbg = " << this->DItbg << "\n";
    file << "DOtbg = " << this->DOtbg << "\n";
    file << "--------------------------------\n";
}

#pragma package(smart_init)
