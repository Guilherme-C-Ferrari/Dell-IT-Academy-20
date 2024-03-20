#pragma once
# include "Edition.h"
# include <stdlib.h>
# include <string>
# include <windows.h>

// Arquivo de Cabeçalho da Classe Bookmaker.
// A Classe Bookmaker abaixo representa o sistema de apostas, a parte onde as edições são feitas e organizadas.
// Nessa classe também é onde ocorre a interação com o operador do sistema de controle de apostas.

class Bookmaker {

private:

	vector<Edition> editions; // Atributo vetor do tipo "Edition" que representa as edições salvas no sistema de apostas.

public:
	// Construtor da classe Bookmaker.
	Bookmaker();

	// Método que inicializa o sistema de apostas.
	void Start();

	// Método que roda o sistema de apostas, onde fica o menu que será usado pelo usuário para acessar as funcionalidades.
	void Run();

	// Método que finaliza o sistema de apostas.
	void Finish();

	// Método que testa exceções as exceções de inputs do sistema de apostas.
	int TestException(string arg_string);
	
	// Método que inicia uma nova edição.
	void StartNewEdition();

	// Método que inicia a fase de apostas de uma edição.
	void StartBetPhaseOnEdition(int indexEdition);

	// Método que inicia a fase de sorteio de uma edição.
	void StartDrawPhaseOnEdtion(int indexEdition);

	// Método que inicia a fase de apuração de uma edição.
	bool StartCoutingPhaseOnEdition(int indexEdition);

	// Método que inicia a fase de premiação de uma edição.
	void StartAwardPhaseOnEdition(int indexEdition);

	// Método que checa as edições anteriores e mostra elas.
	void CheckPastEditions();
};