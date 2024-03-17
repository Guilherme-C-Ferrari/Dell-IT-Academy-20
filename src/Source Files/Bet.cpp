#include "../Header Files/Bet.h"

Bet::Bet() {
	code = 0;
	memset(numbers, 0, sizeof(numbers));
}

int Bet::GetCode() {
	return code;
}
void Bet::SetCode(int c) {
	code = c;
}

int* Bet::GetNumbers() {
	return numbers;
}
void Bet::SetNumbers(int c[5]) {
	for (int i = 0; i < 5; i++) {
		numbers[i] = c[i];
	}
}
void Bet::SetNumbersRandomly() {
	bool testBool = false;
	int number;

	for (int i = 0; i < 5; i++) {
		while (testBool == false) {
			srand((unsigned)time(NULL));
			number = rand() % 50 + 1;

			for (int j = 0; j < sizeof(numbers); j++) {
				if (numbers[j] != number) {
					testBool = true;
				}
				else {
					testBool = false;
				}
			}
		}
	}
}

Bettor Bet::GetBettor() {
	return bettor;
}
void Bet::SetBettor(string name, string cpf) {
	bettor.SaveBettorData(name, cpf);
}