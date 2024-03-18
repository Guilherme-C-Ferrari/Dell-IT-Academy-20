#pragma once
# include "Bet.h"

class Edition {

private:

	int edition_number;
	vector<Bet> bets = vector<Bet>(0);
	vector<int> winner_numbers = vector<int>(5);
	vector<Bettor> winner = vector<Bettor>(0);

public:
	Edition();

	void RegisterNewBet(string name, string cpf, int option, int n[5]);

	void ShowBets();

	void ExecuteDrawPhase();

	void ExecuteCoutingPhase();

	void ExecuteAwardPhase();

	void ShowEditionData();
};
