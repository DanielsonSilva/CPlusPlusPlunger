/**
 * @file CasingDados.cpp
 * @author Joilson, Danielson
 *  Implementação da interface para o Casing do sistema.
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
 * @brief Classe que define os dados necessários para o anular.
 */
class CasingDados {
	public:
		/** Função que pega a instância da classe */
		static CasingDados* getInstance();
		// Dados utilizados na simulação
		/** Diâmetro interno do anular */
		double DIcsg;
		// Dados não utilizados na simulação apenas para informação
		/** Comprimento do anular do sistema */
		double comprimento;
		/** Rugosidade do anular */
		double rugosidade;
		/** Diâmetro externo do anular */
		double DEcsg;
		/** Peso do anular */
		double peso;
		/** Destrutor da classe */
		~CasingDados();
		/** Reinicia os dados do objeto */
		void Limpar();
        /** Imprime as variáveis da classe */
		void imprimirVariaveis(ofstream& file);

	private:
		/** Construtor da classe */
		CasingDados();
		/** Instância unica do objeto */
		static CasingDados* instance;
		/** Flag que informa se a classe foi instanciada ou não */
		static bool instanceFlag;
};
#endif
