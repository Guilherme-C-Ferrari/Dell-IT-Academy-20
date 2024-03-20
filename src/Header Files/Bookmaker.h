#pragma once
# include "Edition.h"
# include <stdlib.h>
# include <string>
# include <windows.h>


class Bookmaker {

private:

	vector<Edition> editions;

public:
	// Construtor da classe Bookmaker.
	Bookmaker();

	// M�todo que inicializa o programa.
	void Start();

	// M�todo que roda o programa, onde fica o menu que ser� usado pelo usu�rio para acessar as funcionalidades.
	void Run();

	// M�todo que finaliza o programa.
	void Finish();

	// M�todo que testa exce��es.
	int TestException(string arg_string);
	
	// M�todo que inicia uma nova edi��o.
	void StartNewEdition();

	// M�todo que inicia a fase de edi��o.
	void StartBetPhaseOnEdition(int indexEdition);

	// M�todo que inicia a fase de sorteio.
	void StartDrawPhaseOnEdtion(int indexEdition);

	// M�todo que inicia a fase de apura��o.
	bool StartCoutingPhaseOnEdition(int indexEdition);

	// M�todo que inicia a fase de premia��o.
	void StartAwardPhaseOnEdition(int indexEdition);

	// M�todo que checa as edi��es anteriores.
	void CheckPastEditions();
};