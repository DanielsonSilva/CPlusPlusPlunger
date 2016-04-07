/*********************************************************************
 * Universidade Federal do Rio Grande do Norte
 * Laboratório de Automação em Petróleo
 * Projeto AUTOPOC - Simulador de Plunger Lift
 *
 * Financiadores: CENPES/Petrobras, FINEP e CNPq
 *
 * Autores:
 *  Cristiano Gurgel de Castro <crisgc@dca.ufrn.br>
 * 	Victor Hugo Freitas de Oliveira <victorhugo@dca.ufrn.br>
 *	Victor Moreira Araujo <sttop@engcomp.ufrn.br>
 *
 * Responsável:
 * 	Prof. Andrés Ortiz Salazar <andres@dca.ufrn.br>
 ********************************************************************/

 #include "Conversao.h"

Conversao* Conversao :: instance = NULL ;
bool Conversao :: instanceFlag = false ;

Conversao* Conversao :: getInstance() {
	if ( ! instanceFlag ) {
		Conversao :: instance = new Conversao() ;
	}
	return Conversao :: instance ;
}

//! Construtor padrão: vazio
Conversao :: Conversao() {
	Conversao :: instanceFlag = true ;
}

//! Destrutor Padrão: vazio
Conversao :: ~Conversao() {
	Conversao :: instanceFlag = false ;
}


float Conversao :: pascalToPsi( const float pasc ) {
	return pasc/6894.757;
}
