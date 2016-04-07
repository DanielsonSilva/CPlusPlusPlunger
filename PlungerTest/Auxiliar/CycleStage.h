/**
 * @file CycleStage.h
 * @author Joilson
 *  Define est�gios da simula��o.
 * 	Revis�es:
 *
 */
#ifndef __CYCLESTAGE_H__
#define __CYCLESTAGE_H__
/** Enumera��o com os est�gios de um ciclo de plunger lift */
enum CycleStage {
	/** Subida do pist�o */
	PLUNGER_RISE = 0 ,
	/** Produ��o */
	PRODUCTION = 100 ,
	/** Afterflow */
	AFTERFLOW = 200 ,
	/** Build-up */
	BUILDUP = 300
} ;
#endif
