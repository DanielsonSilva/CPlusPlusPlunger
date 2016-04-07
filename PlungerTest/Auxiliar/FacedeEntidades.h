/**
 * @file FacedeEntidades.h
 * @author Equipe AUTOPOC Plunger Lift
 *  Objeto que faz parte do padrao Facade para acessar as entidades do sistema.
 * 	Revisoes:
 *
 */
//---------------------------------------------------------------------------
#ifndef FacedeEntidadesH
#define FacedeEntidadesH
//---------------------------------------------------------------------------
#include <fstream>
#include "TubingDados.h"
#include "CasingDados.h"
#include "ValvulaMotora.h"
#include "LinhaProducao.h"
#include "Reservatorio.h"
#include "Pistao.h"
#include "Fluido.h"
#include "TemposIniciais.h"
#include "VariaveisSaida.h"
using namespace std;
/**
 * @brief Classe que serve de fachada para acessar os objetos do sistema.
 */
class FacedeEntidades {
	public:
		/** Funcao para pegar a instancia unica da classe. */
		static FacedeEntidades* getInstance();
		/** Dados referentes à coluna de producao.  */
		TubingDados* tubing;
		/** Dados referentes ao anular.             */
		CasingDados* casing;
		/** Dados referentes à válvula motora.      */
		ValvulaMotora* valvula;
		/** Dados referentes à linha de produção.   */
		LinhaProducao* linhaPro;
		/** Dados do reservatório do poço.          */
		Reservatorio* reservat;
		/** Dados referentes ao pistão usado.       */
		Pistao* pistao;
		/** Dados do fluido do reservatório.        */
		Fluido* fluido;
		/** Tempos de abertura e fechamento.        */
		TemposIniciais* tempos;
		/** Variaveis concernentes à interface.     */
		VariaveisSaida* varSaida;
		/** Destrutor. */
		~FacedeEntidades();
		/** Reseta os valores de todas as variaveis do sistema. */
		void Limpar();
		/** Imprime as variáveis da classe */
		void imprimirVariaveis(ofstream& file);
	private:
		/** Construtor da classe. */
		FacedeEntidades();
		/** Instancia unica da classe (Singleton). */
		static FacedeEntidades* instance;
		/** Informa se a classe ja foi instanciada ou nao. */
		static bool instanceFlag;
		/** Inicia valores da classe. */
		void init();
};
#endif
