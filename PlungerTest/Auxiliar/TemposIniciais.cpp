//---------------------------------------------------------------------------


#pragma hdrstop

#include "TemposIniciais.h"
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------

TemposIniciais* TemposIniciais :: instance = NULL ;
bool TemposIniciais :: instanceFlag = false ;

TemposIniciais* TemposIniciais :: getInstance() {
        if ( ! instanceFlag ){
                TemposIniciais :: instance = new TemposIniciais();
                instanceFlag = true;
        }
        return TemposIniciais :: instance;
}

TemposIniciais::TemposIniciais() {
}

TemposIniciais::~TemposIniciais() {
	this->instanceFlag = false;
}

void TemposIniciais::Limpar() {

	Afterflow = 0;
	Offtime = 0;
	Ontime = 0;
	PcsgT = 0;
	Ltbg = 0;
	Lslg = 0;
	Controller = false;

}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void TemposIniciais::imprimirVariaveis(ofstream& file) {
    file << "Initial Condition Data:\n";
    file << "Afterflow = " << this->Afterflow << "\n";
    file << "Offtime = " << this->Offtime << "/n";
    file << "Ontime = " << this->Ontime << "/n";
    file << "PcsgT = " << this->PcsgT << "/n";
    file << "Ltbg = " << this->Ltbg << "/n";
    file << "Lslg = " << this->Lslg << "/n";
    file << "Controller = " << this->Controller << "/n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
