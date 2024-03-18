#include "../Header Files/Edition.h"

Edition::Edition() {
	edition_number = 0;
	bets.resize(0);
}

void Edition::RegisterNewBet(string name, string cpf, int option, int n[5]) {
	int indexBet = bets.size();
	bets.resize(indexBet + 1);

	bets[indexBet].SetCode(1000 + indexBet);
	if (option == 1) {
		bets[indexBet].SetNumbers(n);
	}
	else if (option == 2) {
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

}

void Edition::ExecuteCoutingPhase() {

}

void Edition::ExecuteAwardPhase() {

}

void Edition::ShowEditionData() {

}