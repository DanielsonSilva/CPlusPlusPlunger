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

#ifndef __SIMULATORPOINT_H__
#define __SIMULATORPOINT_H__

#include <cstddef>
#include <vector>

using std :: vector ;

#include "CycleStage.h"

//! Estrutura para armazenar os pontos gerados pelo simulador
/*!
 * Os dados armazenados são os seguintes respectivamente
 * - Pressão no topo da coluna de produção
 * - Pressão no topo da golfada
 * - Pressão na base do anular
 * - Pressão no topo do anular
 * - Altura da golfada
 * - Altura da golfada no fundo da coluna
 * - Posição do pistão
 * - Velocidade do pistão
 * - Vazão de líquido do reservatório
 * - Vazão de gás do reservatório
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
