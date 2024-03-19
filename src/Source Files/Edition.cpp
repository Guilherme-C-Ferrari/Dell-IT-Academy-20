#include "../Header Files/Edition.h"

Edition::Edition() {
	edition_number = 0;
	winner_numbers.resize(5);
	bets.resize(0);
	winners.resize(0);
	bettedNumbers.resize(0);
}

void Edition::SetEditionNumber(int e) {
	edition_number = e;
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
	int number = 0;

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
	int tempArray[5];

	for (int i = 0; i < bets.size(); i++) {
		testWinner = 0;
		copy(bets[i].GetNumbers(), bets[i].GetNumbers() + 5, tempArray);

		if (winner_numbers.size() == 5) {
			for (int j = 0; j < size(tempArray); j++) {
				AddBettedNumberInEdition(tempArray[j]);
			}
		}

		for (int j = 0; j < winner_numbers.size(); j++) {
			if (find(begin(tempArray), end(tempArray), winner_numbers[j]) != end(tempArray)) {
				testWinner++;
			}
		}

		if (testWinner == 5) {
			winners.push_back(bets[i]);
		}
	}

	ShowDataOffCoutingPhase();
	if (winners.size() > 0) {
		return true;
	}

	return false;
}

void Edition::AddBettedNumberInEdition(int n) {
	bool testBool = false;
	int index = 0;

	while (index < bettedNumbers.size() && testBool == false) {
		if (n == bettedNumbers[index].number) {
			bettedNumbers[index].quantity = bettedNumbers[index].quantity + 1;
			testBool = true;
		}
		index++;
	}

	if (testBool == false) {
		bettedNumbers.resize(bettedNumbers.size() + 1);
		index = bettedNumbers.size() - 1;
		bettedNumbers[index].number = n;
		bettedNumbers[index].quantity = 1;
	}
}

void Edition::ShowDataOffCoutingPhase() {
	int* tempArray;
	Bettor tempBettor;
	vector<BettedNumberInEdition> reorderedVector;

	cout << "\n---------------------Fase de Apuração----------------------\n";
	cout << "\nNúmeros vencedores: ";
	for (int i = 0; i < winner_numbers.size(); i++) {
		cout << winner_numbers[i] << " ";
	}
	cout << "\n\nRodadas realizadas: " << winner_numbers.size() - 4;
	cout << "\n\nQuantidade de apostas vencedoras: " << winners.size();
	cout << "\n\nLista de apostas vencedoras: ";
	for (int i = 0; i < winners.size(); i++) {
		tempBettor = winners[i].GetBettor();
		tempArray = winners[i].GetNumbers();
		cout << "\n\nAposta número: " << winners[i].GetCode();
		cout << "\nApostador: " << tempBettor.GetName() << " - CPF: " << tempBettor.GetCPF();
		cout << "\nNúmeros: ";
		for (int j = 0; j < 5; j++) {
			cout << tempArray[j] << " ";
		}
	}
	cout << "\n\nLista de números apostados:\n";
	cout << "Número Apostado - Quantidade de apostas\n";

	sort(bettedNumbers.begin(), bettedNumbers.end(), [](const BettedNumberInEdition& lhs, const BettedNumberInEdition& rhs) {
		return lhs.quantity > rhs.quantity;
	});

	for (int i = 0; i < bettedNumbers.size(); i++) {
		cout << bettedNumbers[i].number << " - " << bettedNumbers[i].quantity << endl;
	}
}

void Edition::ExecuteAwardPhase() {
	Bettor tempBettor;

	if (winners.size() > 0) {
		cout << "\n---------------------Fase de Premiação----------------------\n";
		cout << "\nParabéns aos ganhadores: \n\n";
		for (int i = 0; i < winners.size(); i++) {
			tempBettor = winners[i].GetBettor();
			cout << tempBettor.GetName() << endl;
		}

		if (winners.size() == 1) {
			cout << "\nO premio de 1.000.000 de reais foi dado ao vencedor.\n";
		} else {
			cout << "\nO premio de 1.000.000 de reais foi dividido entre o(s) " << winners.size() << " vencedores.";
			cout << "\nPremio divido: " << 1000000/ winners.size() << "\n";
		}
	} else {
		cout << "\nNão houveram vencedores.\n";
	}
}

void Edition::ShowEditionData() {
	int* tempArray;
	Bettor tempBettor;
	vector<BettedNumberInEdition> reorderedVector;

	cout << "\nNúmero da edição: " << edition_number;
	cout << "\nNúmeros vencedores: ";
	for (int i = 0; i < winner_numbers.size(); i++) {
		cout << winner_numbers[i] << " ";
	}

	cout << "\n\nRodadas realizadas: " << winner_numbers.size() - 4;
	cout << "\n\nQuantidade de apostas vencedoras: " << winners.size();

	cout << "\n\nLista de apostas vencedoras: ";
	if (winners.size() == 0) {
		cout << "\n\nNenhuma aposta vencedora até o momento.";
	}
	else {
		for (int i = 0; i < winners.size(); i++) {
			tempBettor = winners[i].GetBettor();
			tempArray = winners[i].GetNumbers();
			cout << "\nAposta número: " << winners[i].GetCode();
			cout << "\nApostador: " << tempBettor.GetName() << " - CPF: " << tempBettor.GetCPF();
			cout << "\nNúmeros: ";
			for (int j = 0; j < 5; j++) {
				cout << tempArray[j] << " ";
			}
		}
	}

	cout << "\n\nLista de números apostados:\n";
	cout << "\nNúmero Apostado - Quantidade de apostas\n";
	for (int i = 0; i < bettedNumbers.size(); i++) {
		cout << bettedNumbers[i].number << " - " << bettedNumbers[i].quantity << endl;
	}
	cout << "\n------------------------------------------------------------\n";
}