#pragma once
# include "Bet.h"
# include <algorithm>

struct BettedNumberInEdition {
	int number = 0;
	int quantity = 0;
};

class Edition {

private:

	int edition_number;
	vector<int> winner_numbers;
	vector<Bet> bets;
	vector<Bet> winners;
	vector<BettedNumberInEdition> bettedNumbers;

public:
	Edition();

	void SetEditionNumber(int e);

	void RegisterNewBet(string name, string cpf, int option, int n[5]);

	void ShowBets();

	bool CheckExistenceOfBets();

	void ExecuteDrawPhase();

	bool ExecuteCoutingPhase();

	void AddBettedNumberInEdition(int n);

	void ShowDataOffCoutingPhase();

	void ExecuteAwardPhase();

	void ShowEditionData();
};
