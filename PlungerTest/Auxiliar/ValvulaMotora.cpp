//---------------------------------------------------------------------------


#pragma hdrstop

#include "ValvulaMotora.h"

//---------------------------------------------------------------------------


ValvulaMotora* ValvulaMotora :: instance = NULL ;
bool ValvulaMotora :: instanceFlag = false ;

ValvulaMotora* ValvulaMotora :: getInstance() {
        if ( ! instanceFlag ){
                ValvulaMotora :: instance = new ValvulaMotora();
                instanceFlag = true;
        }
        return ValvulaMotora :: instance;
}

ValvulaMotora::ValvulaMotora()
{
}

ValvulaMotora::~ValvulaMotora()
{
	this->instanceFlag = false;
}

void ValvulaMotora::Limpar() {

	Dab = 0;

}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void ValvulaMotora::imprimirVariaveis(ofstream& file) {
    file << "Motor Valve Data:\n";
    file << "Dab = " << this->Dab << "\n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
