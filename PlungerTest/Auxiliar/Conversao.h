/*********************************************************************
 * Universidade Federal do Rio Grande do Norte
 * Laborat�rio de Automa��o em Petr�leo
 * Projeto AUTOPOC - Simulador de Plunger Lift
 *
 * Financiadores: CENPES/Petrobras, FINEP e CNPq
 *
 * Autores:
 *  Cristiano Gurgel de Castro <crisgc@dca.ufrn.br>
 * 	Victor Hugo Freitas de Oliveira <victorhugo@dca.ufrn.br>
 *	Victor Moreira Araujo <sttop@engcomp.ufrn.br>
 *
 * Respons�vel:
 * 	Prof. Andr�s Ortiz Salazar <andres@dca.ufrn.br>
 ********************************************************************/

#ifndef __CONVERSAO_H__
#define __CONVERSAO_H__

#include <cstddef>

class Conversao{
public:
	static Conversao* getInstance();
	float pascalToPsi( const float  pasc);


private:
	//! �nica inst�ncia da classe
	static Conversao* instance ;

	//! Flag para indicar se h� uma inst�ncia da classe
	static bool instanceFlag ;

	Conversao() ;
	~Conversao() ;

};

#endif  // __CONVERSAO_H__
