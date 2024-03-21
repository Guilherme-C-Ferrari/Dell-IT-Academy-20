#pragma once
# include "Bet.h"

// Estrutura que representa os números que foram apostados na edição.
struct BettedNumberInEdition {
	int number = 0; // Valor do número que foi apostado na edição
	int quantity = 0; // Quantidade de vezes que o número foi apostado.
};

// Arquivo de Cabeçalho da Classe Edition.
// A Classe Edition abaixo representa as edições em que ocorrem as apostas.
// Cada edição é como uma novo jogo, que possui seu próprios números sorteados, apostas e vencedores.

class Edition {

private:

	int edition_number; // Atributo que representa o número da edição.
	vector<int> winner_numbers; // Atributo vetor do tipo "int" que representa os números vencedores da edição. 
	vector<Bet> bets; // Atributo vetor do tipo "Bet" que representa as apostas realizadas na edição.
	vector<Bet> winners; // Atributo vetor do tipo "Bet" que representa as apostas vencedoras da edição.
	vector<BettedNumberInEdition> bettedNumbers; // Atributo vetor da estrutura "BettedNumberInEdition" que representa os números apostados na edição.

public:
	// Método construtor da Classe Edition.
	Edition();

	// Método Setter do atributo "edition_number".
	void SetEditionNumber(int e);

	// Método que realiza o registro de uma nova aposta na edição.
	void RegisterNewBet(string name, string cpf, int option, int n[5]);

	// Método que mostra as apostas registradas na edição.
	void ShowBets();

	// Método que checa a existência de apostas na edição.
	bool CheckExistenceOfBets();

	// Método que executa a fase de sorteio da edição.
	void ExecuteDrawPhase();

	// Método que excuta a fase de apuração da edição.
	bool ExecuteCoutingPhase();

	/*
	   Método que adiciona um número a lista de números apostados na edição ou aumenta sua quantidade de usos caso já
	   esteja registrado.
	*/ 
	void AddBettedNumberInEdition(int n);

	// Método que mostra as informações da fase de apuração.
	void ShowDataOffCoutingPhase();

	// Método que executa a fase de premiação da edição.
	void ExecuteAwardPhase();

	// Método que mostra todos os dados da edição.
	void ShowEditionData();
};
