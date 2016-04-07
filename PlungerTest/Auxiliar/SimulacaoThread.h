//---------------------------------------------------------------------------
#ifndef SimulacaoThreadH
#define SimulacaoThreadH
//---------------------------------------------------------------------------
#include "Simulacao.h"
#include "FacedeEntidades.h"
#include "ConstantesUniversais.h"
#include "VariaveisAuxiliares.h"

class SimulacaoThread {
	private:
		Simulacao* simulacao ;
		bool pausado;
	protected:
		void Execute() ;
	public:
		SimulacaoThread(Simulacao* sm, bool CreateSuspended);
		void pausarSimulacao();
		void setPausado();
		void continuarSimulacao();
		void iniciarSimulacao();
		int pararSimulacao();
		bool getPausado();
};

#endif
