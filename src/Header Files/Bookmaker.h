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

	// Método que inicializa o programa.
	void Start();

	// Método que roda o programa, onde fica o menu que será usado pelo usuário para acessar as funcionalidades.
	void Run();

	// Método que finaliza o programa.
	void Finish();

	// Método que testa exceções.
	int TestException(string arg_string);
	
	// Método que inicia uma nova edição.
	void StartNewEdition();

	// Método que inicia a fase de edição.
	void StartBetPhaseOnEdition(int indexEdition);

	// Método que inicia a fase de sorteio.
	void StartDrawPhaseOnEdtion(int indexEdition);

	// Método que inicia a fase de apuração.
	bool StartCoutingPhaseOnEdition(int indexEdition);

	// Método que inicia a fase de premiação.
	void StartAwardPhaseOnEdition(int indexEdition);

	// Método que checa as edições anteriores.
	void CheckPastEditions();
};