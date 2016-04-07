/**
 * @file EquacoesAuxiliares.h
 * @author Equipe AUTOPOC Plunger Lift
 *  Implementa��o do modelo matem�tico da simula��o.
 * 	Revis�es:
 *
 */
//---------------------------------------------------------------------------
#ifndef EquacoesAuxiliaresH
#define EquacoesAuxiliaresH
//---------------------------------------------------------------------------
#include "EquacoesUtilitarias.h"
#include "VariaveisAuxiliares.h"
#include "CycleStage.h"
#include "Conversao.h"
#include <iostream>
#include <cmath>
/**
 * @brief Objeto que armazena as fun��es do modelo matem�tico.
 */
class EquacoesAuxiliares {
public:
	/** Fun��o para pegar inst�ncia da classe */
	static EquacoesAuxiliares* getInstance();
	/** Fun��o que acerta par�metros para iniciar simula��o */
	void iniciarSimulacao();
	/** Reseta todos os dados da simula��o */
	void Limpar();
	/** Pega o ID da simula��o */
	int getIdSimulacao();
	/** Seta o ID da simula��o */
	void setIdSimulacao(int id);
	/** Fun��o para iniciar um ciclo da simula��o */
	bool inicioCiclo();
	/** Modelo matem�tico para a etapa de subida do pist�o */
	void subidaPistao();
	/** Modelo matem�tico para a etapa de produ��o de l�quido */
	void producaoLiquido();
	/** Modelo matem�tico para a etapa de controle da simula��o */
	void Controle();
	/** Modelo matem�tico para a etapa de afterflow */
	void Afterflow();
	/** Modelo matem�tico para a etapa de build up */
	void OffBuildUp(bool ChegouSup);
	/** Altera par�metros para alterar a v�lvula do po�o */
	void alterValvula();

private:
	/** Fun��o que envia uma vari�vel de ciclo para a interface */
	void enviarVarCiclo(int ciclovar, double valor);
	/** Envia uma mensagem de final de ciclo para a interface */
	void enviarFimCiclo(double tempo);
	/** Cria uma mensagem de amostra para enviar para a interface */
	void criarMensagem(CycleStage stage);
	/** Seta a precis�o de um n�mero em tantas casas decimais */
	double setPrecision(double x, int precisao);
	/** �nica inst�ncia da classe */
	static EquacoesAuxiliares* instance;
	/** Flag para indicar se h� inst�ncia ativa */
	static bool instanceFlag;
	/** Construtor da classe */
	EquacoesAuxiliares();
	/** Guarda o tempo de simula��o */
	float tempo;
	/** Identifica a simula��o (n�o usada) */
	int idSimulacao;
	/** Identifica a simula��o (n�o usada) */
	int idRamoSimulacao;
	/** Guarda o n�mero de pontos descartados para comparar com a amostragem */
	int quantidadePontos;
	/** Mostra quantos pontos s�o descartados para se enviar um ponto para
			interface */
	int periodoAmostragem;
	/** Tamanho da fila de espera de pontos para ser enviado para a interface */
	int bufferSendPoints;
	/** Mostra se passa ou n�o pelo controle no algoritmo */
	bool byPassController;
	/** for�a o envio do ponto inicial da etapa */
	bool forcarPontosI;
	/** for�a o envio do ponto final da etapa */
	bool forcarPontosF;
	/** Par�metro que verifica se o pedido de altera��o da v�lvula motora foi
			feito ou n�o */
	bool alterarValvula;
};
#endif
