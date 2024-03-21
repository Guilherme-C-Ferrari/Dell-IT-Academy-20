#pragma once
# include "Bet.h"

// Estrutura que representa os n�meros que foram apostados na edi��o.
struct BettedNumberInEdition {
	int number = 0; // Valor do n�mero que foi apostado na edi��o
	int quantity = 0; // Quantidade de vezes que o n�mero foi apostado.
};

// Arquivo de Cabe�alho da Classe Edition.
// A Classe Edition abaixo representa as edi��es em que ocorrem as apostas.
// Cada edi��o � como uma novo jogo, que possui seu pr�prios n�meros sorteados, apostas e vencedores.

class Edition {

private:

	int edition_number; // Atributo que representa o n�mero da edi��o.
	vector<int> winner_numbers; // Atributo vetor do tipo "int" que representa os n�meros vencedores da edi��o. 
	vector<Bet> bets; // Atributo vetor do tipo "Bet" que representa as apostas realizadas na edi��o.
	vector<Bet> winners; // Atributo vetor do tipo "Bet" que representa as apostas vencedoras da edi��o.
	vector<BettedNumberInEdition> bettedNumbers; // Atributo vetor da estrutura "BettedNumberInEdition" que representa os n�meros apostados na edi��o.

public:
	// M�todo construtor da Classe Edition.
	Edition();

	// M�todo Setter do atributo "edition_number".
	void SetEditionNumber(int e);

	// M�todo que realiza o registro de uma nova aposta na edi��o.
	void RegisterNewBet(string name, string cpf, int option, int n[5]);

	// M�todo que mostra as apostas registradas na edi��o.
	void ShowBets();

	// M�todo que checa a exist�ncia de apostas na edi��o.
	bool CheckExistenceOfBets();

	// M�todo que executa a fase de sorteio da edi��o.
	void ExecuteDrawPhase();

	// M�todo que excuta a fase de apura��o da edi��o.
	bool ExecuteCoutingPhase();

	/*
	   M�todo que adiciona um n�mero a lista de n�meros apostados na edi��o ou aumenta sua quantidade de usos caso j�
	   esteja registrado.
	*/ 
	void AddBettedNumberInEdition(int n);

	// M�todo que mostra as informa��es da fase de apura��o.
	void ShowDataOffCoutingPhase();

	// M�todo que executa a fase de premia��o da edi��o.
	void ExecuteAwardPhase();

	// M�todo que mostra todos os dados da edi��o.
	void ShowEditionData();
};
