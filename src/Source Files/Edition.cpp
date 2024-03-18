#include "../Header Files/Edition.h"

Edition::Edition() {
	edition_number = 0;
	bets.resize(0);
	winner_numbers.resize(5);
	winners.resize(0);
}

void Edition::RegisterNewBet(string name, string cpf, int option, int n[5]) {
	int indexBet = bets.size();
	bets.resize(indexBet + 1);

	bets[indexBet].SetCode(1000 + indexBet);
	if (option == 1) {
		bets[indexBet].SetNumbers(n);
	} else if (option == 2) {
		bets[indexBet].SetNumbersRandomly();
	}
	bets[indexBet].SetBettor(name, cpf);
}

void Edition::ShowBets() {
	Bettor tempBettor;
	int* tempArray;
	for (int i = 0; i < bets.size(); i++) {
		tempBettor = bets[i].GetBettor();
		tempArray = bets[i].GetNumbers();
		cout << "\nAposta número: " << bets[i].GetCode();
		cout << "\nApostador: " << tempBettor.GetName() << " - CPF: " << tempBettor.GetCPF();
		cout << "\nNúmeros: ";
		for (int j = 0; j < 5; j++) {
			cout << tempArray[j] << " ";
		}
		cout << endl;
	}

	if (bets.size() == 0) {
		cout << "\nNenhuma aposta registrada.\n";
	}
}

void Edition::ExecuteDrawPhase() {
	bool testBool = false;
	int number;

	if (winner_numbers[0] == 0) {
		for (int i = 0; i < 5; i++) {
			testBool = false;
			while (testBool == false) {
				number = rand() % 50 + 1;

				if (find(begin(winner_numbers), end(winner_numbers), number) == end(winner_numbers)) {
					testBool = true;
				}
				else {
					testBool = false;
				}

				if (testBool == true) {
					winner_numbers[i] = number;
				}
			}
		}
	} else {
		testBool = false;
		while (testBool == false) {
			number = rand() % 50 + 1;

			if (find(begin(winner_numbers), end(winner_numbers), number) == end(winner_numbers)) {
				testBool = true;
			}
			else {
				testBool = false;
			}

			if (testBool == true) {
				winner_numbers.push_back(number);
			}
		}
	}
}

bool Edition::ExecuteCoutingPhase() {
	int testWinner = 0;
	int* tempArray;

	for (int i = 0; i < bets.size(); i++) {
		testWinner = 0;
		tempArray = bets[i].GetNumbers();
		for (int j = 0; j < winner_numbers.size(); j++) {
			if (tempArray[i] == winner_numbers[j]) {
				testWinner++;
			}
		}

		if (testWinner == 5) {
			winners.push_back(bets[i].GetBettor());
		}
	}

	if (winners.size() > 0) {
		return true;
	}

	return false;
}

void Edition::ExecuteAwardPhase() {

}

void Edition::ShowEditionData() {

}