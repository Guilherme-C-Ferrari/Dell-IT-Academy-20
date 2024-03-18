#pragma once
# include "Bet.h"

class Edition {

private:

	int edition_number;
	vector<Bet> bets;
	vector<int> winner_numbers;
	vector<Bettor> winners;

public:
	Edition();

	void RegisterNewBet(string name, string cpf, int option, int n[5]);

	void ShowBets();

	void ExecuteDrawPhase();

	bool ExecuteCoutingPhase();

	void ExecuteAwardPhase();

	void ShowEditionData();
};
