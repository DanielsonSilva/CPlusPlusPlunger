/**
 * @file CycleStage.h
 * @author Joilson
 *  Define estágios da simulação.
 * 	Revisões:
 *
 */
#ifndef __CYCLESTAGE_H__
#define __CYCLESTAGE_H__
/** Enumeração com os estágios de um ciclo de plunger lift */
enum CycleStage {
	/** Subida do pistão */
	PLUNGER_RISE = 0 ,
	/** Produção */
	PRODUCTION = 100 ,
	/** Afterflow */
	AFTERFLOW = 200 ,
	/** Build-up */
	BUILDUP = 300
} ;
#endif
