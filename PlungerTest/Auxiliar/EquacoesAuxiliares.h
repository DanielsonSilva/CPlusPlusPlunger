/**
 * @file EquacoesAuxiliares.h
 * @author Equipe AUTOPOC Plunger Lift
 *  Implementação do modelo matemático da simulação.
 * 	Revisões:
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
 * @brief Objeto que armazena as funções do modelo matemático.
 */
class EquacoesAuxiliares {
public:
	/** Função para pegar instância da classe */
	static EquacoesAuxiliares* getInstance();
	/** Função que acerta parâmetros para iniciar simulação */
	void iniciarSimulacao();
	/** Reseta todos os dados da simulação */
	void Limpar();
	/** Pega o ID da simulação */
	int getIdSimulacao();
	/** Seta o ID da simulação */
	void setIdSimulacao(int id);
	/** Função para iniciar um ciclo da simulação */
	bool inicioCiclo();
	/** Modelo matemático para a etapa de subida do pistão */
	void subidaPistao();
	/** Modelo matemático para a etapa de produção de líquido */
	void producaoLiquido();
	/** Modelo matemático para a etapa de controle da simulação */
	void Controle();
	/** Modelo matemático para a etapa de afterflow */
	void Afterflow();
	/** Modelo matemático para a etapa de build up */
	void OffBuildUp(bool ChegouSup);
	/** Altera parâmetros para alterar a válvula do poço */
	void alterValvula();

private:
	/** Função que envia uma variável de ciclo para a interface */
	void enviarVarCiclo(int ciclovar, double valor);
	/** Envia uma mensagem de final de ciclo para a interface */
	void enviarFimCiclo(double tempo);
	/** Cria uma mensagem de amostra para enviar para a interface */
	void criarMensagem(CycleStage stage);
	/** Seta a precisão de um número em tantas casas decimais */
	double setPrecision(double x, int precisao);
	/** Única instância da classe */
	static EquacoesAuxiliares* instance;
	/** Flag para indicar se há instância ativa */
	static bool instanceFlag;
	/** Construtor da classe */
	EquacoesAuxiliares();
	/** Guarda o tempo de simulação */
	float tempo;
	/** Identifica a simulação (não usada) */
	int idSimulacao;
	/** Identifica a simulação (não usada) */
	int idRamoSimulacao;
	/** Guarda o número de pontos descartados para comparar com a amostragem */
	int quantidadePontos;
	/** Mostra quantos pontos são descartados para se enviar um ponto para
			interface */
	int periodoAmostragem;
	/** Tamanho da fila de espera de pontos para ser enviado para a interface */
	int bufferSendPoints;
	/** Mostra se passa ou não pelo controle no algoritmo */
	bool byPassController;
	/** força o envio do ponto inicial da etapa */
	bool forcarPontosI;
	/** força o envio do ponto final da etapa */
	bool forcarPontosF;
	/** Parâmetro que verifica se o pedido de alteração da válvula motora foi
			feito ou não */
	bool alterarValvula;
};
#endif
