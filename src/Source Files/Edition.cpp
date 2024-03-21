#include "../Header Files/Edition.h"

// Arquivo de implementação da Classe Edition.
// Aqui ocorre a implementação dos métodos de mesmo nome declarados e explicados no cabeçalho da classe Edition.

Edition::Edition() {
	edition_number = 0; // Inicializa o atributo com o valor 0.
	winner_numbers.resize(5); // Define o tamanho do vetor como 5.
	bets.resize(0); // Define o tamanho do vetor como 0.
	winners.resize(0); // Define o tamanho do vetor como 0.
	bettedNumbers.resize(0); // Define o tamanho do vetor como 0.
}

// Recebe por meio do argumento "e" o novo valor do atributo "edition_number".
void Edition::SetEditionNumber(int e) {
	edition_number = e;
}

/*
   No método abaixo é realizada o registro de uma aposta, sendo que, a partir
   do argumento "option", é definido se ela usuará números aleatórios ou números escolhidos pelo operador manualmente.
*/
void Edition::RegisterNewBet(string name, string cpf, int option, int n[5]) {
	int indexBet = bets.size(); // Indice que define a posição no vetor onde a aposta será salva.
	bets.resize(indexBet + 1); // Aumenta o tamanho do vetor para alocar mais uma aposta.
	bets[indexBet].SetCode(1000 + indexBet); // Define o código do vetor a partir do número 1000.
	if (option == 1) {
		bets[indexBet].SetNumbers(n);
	} else if (option == 2) {
		bets[indexBet].SetNumbersRandomly();
	}
	bets[indexBet].SetBettor(name, cpf);
}

// O método abaixo passa por todos as apostas salvas no vetor de apostas e imprime seus valores na tela.
void Edition::ShowBets() {
	Bettor tempBettor; // Objeto temporário que recebe os apostadores de cada cartilha de aposta.
	int* tempArray; // Array temporário que recebe os valores dos números apostados em cada cartilha.
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

	// Caso nenhuma aposta tenha sido registrada é mostrada a seguinte mensagem.
	if (CheckExistenceOfBets() == false) {
		cout << "\nNenhuma aposta registrada.\n";
	}
}

// Método que checa a existência de apostas registradas por meio do tamanho do vetor "bets".
bool Edition::CheckExistenceOfBets() {
	if (bets.size() > 0) {
		return true;
	}
	return false;
}

/*
   No método abaixo é realizado o sorteio dos números vencedores pela mesma lógica de aleatóriedade usada para o sorteio
   de números aleatórios para uma cartilha de aposta. No entanto, caso já existam números sorteados, o método sorteia um
   novo número e o adiciona ao vetor, para a lógica de novos números serem sorteados na falta de ganhadores.
*/
void Edition::ExecuteDrawPhase() {
	bool testBool = false; // Variável de teste lógico que define se o número vencedor está na cartela.
	int number = 0; // Variável que recebe o número sorteado.

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

/*
   O método abaixo executa a fase de apuração, comparando os valores dos números sorteados com os valores de todas as cartelas
   de apostas. No caso de um cartela ter seus 5 números entre os números sorteados, a cartela é colocada entre no vetor de 
   vencedores. Caso existam vencedores no final do método, é retornado o valor "true", e caso não existam é retornado o valor
   "false".
*/
bool Edition::ExecuteCoutingPhase() {
	int testWinner = 0; // Variável que testa se a cartela conseguiu 5 números para definir ela como vencedora.
	int tempArray[5]; // Array temporário que recebe os valores dos números apostados em cada cartilha.

	for (int i = 0; i < bets.size(); i++) {
		testWinner = 0;
		copy(bets[i].GetNumbers(), bets[i].GetNumbers() + 5, tempArray);

		// Chama, na primeira vez que o método de apuração é realizado, o método "AddBettedNumberInEdition".
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

	ShowDataOffCoutingPhase(); // Mostra os dados da apuração.
	if (winners.size() > 0) {
		return true;
	}

	return false;
}

// O método abaixo registra um número apostado e incrementa a quantidade de vezes que ele foi utilizado caso já tenha sido registrado.
void Edition::AddBettedNumberInEdition(int n) {
	bool testBool = false; // Variável de teste lógico.
	int index = 0; // Variável de índice que passa pelo vetor de números apostados.

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

// O método abaixo imprime na tela todas as informações apuradas na fase de apuração.
void Edition::ShowDataOffCoutingPhase() {
	int* tempArray; // Array temporário que recebe os valores dos números apostados em cada cartilha vencedora.
	Bettor tempBettor; // Objeto temporário que recebe os apostadores vencedores.

	cout << "\n----------------------Fase de Apuração-----------------------\n";
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
		sort(winners.begin(), winners.end(), [](Bet lhs, Bet rhs) {
			return lhs.GetBettor().GetName() < rhs.GetBettor().GetName();
		});
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
	}

	cout << "\n\nLista de números apostados:\n";
	cout << "Número Apostado - Quantidade de apostas\n";
	sort(bettedNumbers.begin(), bettedNumbers.end(), [](const BettedNumberInEdition lhs, const BettedNumberInEdition rhs) {
		return lhs.quantity > rhs.quantity;
	});
	for (int i = 0; i < bettedNumbers.size(); i++) {
		cout << bettedNumbers[i].number << " - " << bettedNumbers[i].quantity << endl;
	}
}

// O método abaixo realiza a fase de premiação, imprimindo na tela o resultado final.
void Edition::ExecuteAwardPhase() {
	Bettor tempBettor; // Objeto temporário que recebe os apostadores vencedores.

	cout << "\n----------------------Fase de Premiação---------------------\n";
	if (winners.size() > 0) {
		cout << "\nParabéns aos ganhadores: \n\n";
		for (int i = 0; i < winners.size(); i++) {
			tempBettor = winners[i].GetBettor();
			cout << tempBettor.GetName() << endl;
		}

		if (winners.size() == 1) {
			cout << "\nO premio de 1.000.000 de reais foi dado ao vencedor.\n";
		} else {
			cout << "\nO prêmio de 1.000.000 de reais foi dividido entre o(s) " << winners.size() << " vencedores.";
			cout << "\nPremio divido: " << 1000000/ winners.size() << "\n";
		}
	} else {
		cout << "\nNão houveram vencedores.\n";
	}
}

// O método baixo imprime na tela todas as informações da edição.
void Edition::ShowEditionData() {
	int* tempArray; // Array temporário que recebe os valores dos números apostados em cada cartilha vencedora.
	Bettor tempBettor; // Objeto temporário que recebe os apostadores vencedores.

	cout << "\nNúmero da edição: " << edition_number;
	cout << "\nNúmeros vencedores: ";
	for (int i = 0; i < winner_numbers.size(); i++) {
		cout << winner_numbers[i] << " ";
	}

	cout << "\n\nRodadas realizadas: " << winner_numbers.size() - 4;
	cout << "\n\nQuantidade de apostas vencedoras: " << winners.size();

	cout << "\n\nLista de apostas vencedoras: ";
	if (winners.size() == 0) {
		cout << "\n\nNenhuma aposta vencedora.";
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