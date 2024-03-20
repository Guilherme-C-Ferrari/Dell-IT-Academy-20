#pragma once
# include "Bettor.h"
# include <cstdlib>
# include <vector>

class Bet {

private:

	int code;
	int numbers[5];
	Bettor bettor;

public: 
	Bet();

	int GetCode();
	void SetCode(int c);

	int* GetNumbers();
	void SetNumbers(int c[5]);
	void SetNumbersRandomly();

	Bettor GetBettor();
	void SetBettor(string name, string cpf);
};