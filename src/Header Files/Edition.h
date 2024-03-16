#pragma once
# include "Bet.h"

class Edition {

private:

	int edition_number;
	vector<Bet> bets;
	vector<int> winner_numbers = vector<int>(5);
	Bettor winner;

public:

	Edition();
};
