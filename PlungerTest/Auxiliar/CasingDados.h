/**
 * @file CasingDados.cpp
 * @author Joilson, Danielson
 *  Implementa��o da interface para o Casing do sistema.
 * 	Revisoes:
 *
 */
//---------------------------------------------------------------------------
#ifndef CasingDadosH
#define CasingDadosH
//---------------------------------------------------------------------------
#include <fstream>
#include <iostream>
#include<stdlib.h>
using namespace std;
/**
 * @brief Classe que define os dados necess�rios para o anular.
 */
class CasingDados {
	public:
		/** Fun��o que pega a inst�ncia da classe */
		static CasingDados* getInstance();
		// Dados utilizados na simula��o
		/** Di�metro interno do anular */
		double DIcsg;
		// Dados n�o utilizados na simula��o apenas para informa��o
		/** Comprimento do anular do sistema */
		double comprimento;
		/** Rugosidade do anular */
		double rugosidade;
		/** Di�metro externo do anular */
		double DEcsg;
		/** Peso do anular */
		double peso;
		/** Destrutor da classe */
		~CasingDados();
		/** Reinicia os dados do objeto */
		void Limpar();
        /** Imprime as vari�veis da classe */
		void imprimirVariaveis(ofstream& file);

	private:
		/** Construtor da classe */
		CasingDados();
		/** Inst�ncia unica do objeto */
		static CasingDados* instance;
		/** Flag que informa se a classe foi instanciada ou n�o */
		static bool instanceFlag;
};
#endif
