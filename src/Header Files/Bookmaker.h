#pragma once
# include "Edition.h"
# include <stdlib.h>
# include <string>
# include <windows.h>

// Arquivo de Cabe�alho da Classe Bookmaker.
// A Classe Bookmaker abaixo representa o sistema de apostas, a parte onde as edi��es s�o feitas e organizadas.
// Nessa classe tamb�m � onde ocorre a intera��o com o operador do sistema de controle de apostas.

class Bookmaker {

private:

	vector<Edition> editions; // Atributo vetor do tipo "Edition" que representa as edi��es salvas no sistema de apostas.

public:
	// Construtor da classe Bookmaker.
	Bookmaker();

	// M�todo que inicializa o sistema de apostas.
	void Start();

	// M�todo que roda o sistema de apostas, onde fica o menu que ser� usado pelo usu�rio para acessar as funcionalidades.
	void Run();

	// M�todo que finaliza o sistema de apostas.
	void Finish();

	// M�todo que testa exce��es as exce��es de inputs do sistema de apostas.
	int TestException(string arg_string);
	
	// M�todo que inicia uma nova edi��o.
	void StartNewEdition();

	// M�todo que inicia a fase de apostas de uma edi��o.
	void StartBetPhaseOnEdition(int indexEdition);

	// M�todo que inicia a fase de sorteio de uma edi��o.
	void StartDrawPhaseOnEdtion(int indexEdition);

	// M�todo que inicia a fase de apura��o de uma edi��o.
	bool StartCoutingPhaseOnEdition(int indexEdition);

	// M�todo que inicia a fase de premia��o de uma edi��o.
	void StartAwardPhaseOnEdition(int indexEdition);

	// M�todo que checa as edi��es anteriores e mostra elas.
	void CheckPastEditions();
};