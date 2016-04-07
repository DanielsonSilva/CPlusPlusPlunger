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
		/** Dados referentes � coluna de producao.  */
		TubingDados* tubing;
		/** Dados referentes ao anular.             */
		CasingDados* casing;
		/** Dados referentes � v�lvula motora.      */
		ValvulaMotora* valvula;
		/** Dados referentes � linha de produ��o.   */
		LinhaProducao* linhaPro;
		/** Dados do reservat�rio do po�o.          */
		Reservatorio* reservat;
		/** Dados referentes ao pist�o usado.       */
		Pistao* pistao;
		/** Dados do fluido do reservat�rio.        */
		Fluido* fluido;
		/** Tempos de abertura e fechamento.        */
		TemposIniciais* tempos;
		/** Variaveis concernentes � interface.     */
		VariaveisSaida* varSaida;
		/** Destrutor. */
		~FacedeEntidades();
		/** Reseta os valores de todas as variaveis do sistema. */
		void Limpar();
		/** Imprime as vari�veis da classe */
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
