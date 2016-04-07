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

#ifndef __SIMULATORPOINT_H__
#define __SIMULATORPOINT_H__

#include <cstddef>
#include <vector>

using std :: vector ;

#include "CycleStage.h"

//! Estrutura para armazenar os pontos gerados pelo simulador
/*!
 * Os dados armazenados s�o os seguintes respectivamente
 * - Press�o no topo da coluna de produ��o
 * - Press�o no topo da golfada
 * - Press�o na base do anular
 * - Press�o no topo do anular
 * - Altura da golfada
 * - Altura da golfada no fundo da coluna
 * - Posi��o do pist�o
 * - Velocidade do pist�o
 * - Vaz�o de l�quido do reservat�rio
 * - Vaz�o de g�s do reservat�rio
 */
struct SimulatorPoint {

	//! Tempo no qual os pontos foram gerados
	double time ;

	//! Etapa do plunger lift
	CycleStage stage ;

	//! Vetor que armazena os pontos gerados pelo simulador
	vector< double > points ;

} ;

#endif
