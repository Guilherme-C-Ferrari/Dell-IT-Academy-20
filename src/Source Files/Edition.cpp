#include "../Header Files/Edition.h"

// Arquivo de implementa��o da Classe Edition.
// Aqui ocorre a implementa��o dos m�todos de mesmo nome declarados e explicados no cabe�alho da classe Edition.

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
   No m�todo abaixo � realizada o registro de uma aposta, sendo que, a partir
   do argumento "option", � definido se ela usuar� n�meros aleat�rios ou n�meros escolhidos pelo operador manualmente.
*/
void Edition::RegisterNewBet(string name, string cpf, int option, int n[5]) {
	int indexBet = bets.size(); // Indice que define a posi��o no vetor onde a aposta ser� salva.
	bets.resize(indexBet + 1); // Aumenta o tamanho do vetor para alocar mais uma aposta.
	bets[indexBet].SetCode(1000 + indexBet); // Define o c�digo do vetor a partir do n�mero 1000.
	if (option == 1) {
		bets[indexBet].SetNumbers(n);
	} else if (option == 2) {
		bets[indexBet].SetNumbersRandomly();
	}
	bets[indexBet].SetBettor(name, cpf);
}

// O m�todo abaixo passa por todos as apostas salvas no vetor de apostas e imprime seus valores na tela.
void Edition::ShowBets() {
	Bettor tempBettor; // Objeto tempor�rio que recebe os apostadores de cada cartilha de aposta.
	int* tempArray; // Array tempor�rio que recebe os valores dos n�meros apostados em cada cartilha.
	for (int i = 0; i < bets.size(); i++) {
		tempBettor = bets[i].GetBettor();
		tempArray = bets[i].GetNumbers();
		cout << "\nAposta n�mero: " << bets[i].GetCode();
		cout << "\nApostador: " << tempBettor.GetName() << " - CPF: " << tempBettor.GetCPF();
		cout << "\nN�meros: ";
		for (int j = 0; j < 5; j++) {
			cout << tempArray[j] << " ";
		}
		cout << endl;
	}

	// Caso nenhuma aposta tenha sido registrada � mostrada a seguinte mensagem.
	if (CheckExistenceOfBets() == false) {
		cout << "\nNenhuma aposta registrada.\n";
	}
}

// M�todo que checa a exist�ncia de apostas registradas por meio do tamanho do vetor "bets".
bool Edition::CheckExistenceOfBets() {
	if (bets.size() > 0) {
		return true;
	}
	return false;
}

/*
   No m�todo abaixo � realizado o sorteio dos n�meros vencedores pela mesma l�gica de aleat�riedade usada para o sorteio
   de n�meros aleat�rios para uma cartilha de aposta. No entanto, caso j� existam n�meros sorteados, o m�todo sorteia um
   novo n�mero e o adiciona ao vetor, para a l�gica de novos n�meros serem sorteados na falta de ganhadores.
*/
void Edition::ExecuteDrawPhase() {
	bool testBool = false; // Vari�vel de teste l�gico que define se o n�mero vencedor est� na cartela.
	int number = 0; // Vari�vel que recebe o n�mero sorteado.

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
   O m�todo abaixo executa a fase de apura��o, comparando os valores dos n�meros sorteados com os valores de todas as cartelas
   de apostas. No caso de um cartela ter seus 5 n�meros entre os n�meros sorteados, a cartela � colocada entre no vetor de 
   vencedores. Caso existam vencedores no final do m�todo, � retornado o valor "true", e caso n�o existam � retornado o valor
   "false".
*/
bool Edition::ExecuteCoutingPhase() {
	int testWinner = 0; // Vari�vel que testa se a cartela conseguiu 5 n�meros para definir ela como vencedora.
	int tempArray[5]; // Array tempor�rio que recebe os valores dos n�meros apostados em cada cartilha.

	for (int i = 0; i < bets.size(); i++) {
		testWinner = 0;
		copy(bets[i].GetNumbers(), bets[i].GetNumbers() + 5, tempArray);

		// Chama, na primeira vez que o m�todo de apura��o � realizado, o m�todo "AddBettedNumberInEdition".
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

	ShowDataOffCoutingPhase(); // Mostra os dados da apura��o.
	if (winners.size() > 0) {
		return true;
	}

	return false;
}

// O m�todo abaixo registra um n�mero apostado e incrementa a quantidade de vezes que ele foi utilizado caso j� tenha sido registrado.
void Edition::AddBettedNumberInEdition(int n) {
	bool testBool = false; // Vari�vel de teste l�gico.
	int index = 0; // Vari�vel de �ndice que passa pelo vetor de n�meros apostados.

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

// O m�todo abaixo imprime na tela todas as informa��es apuradas na fase de apura��o.
void Edition::ShowDataOffCoutingPhase() {
	int* tempArray; // Array tempor�rio que recebe os valores dos n�meros apostados em cada cartilha vencedora.
	Bettor tempBettor; // Objeto tempor�rio que recebe os apostadores vencedores.

	cout << "\n----------------------Fase de Apura��o-----------------------\n";
	cout << "\nN�meros vencedores: ";
	for (int i = 0; i < winner_numbers.size(); i++) {
		cout << winner_numbers[i] << " ";
	}
	cout << "\n\nRodadas realizadas: " << winner_numbers.size() - 4;
	cout << "\n\nQuantidade de apostas vencedoras: " << winners.size();
	cout << "\n\nLista de apostas vencedoras: ";
	if (winners.size() == 0) {
		cout << "\n\nNenhuma aposta vencedora at� o momento.";
	}
	else {
		sort(winners.begin(), winners.end(), [](Bet lhs, Bet rhs) {
			return lhs.GetBettor().GetName() < rhs.GetBettor().GetName();
		});
		for (int i = 0; i < winners.size(); i++) {
			tempBettor = winners[i].GetBettor();
			tempArray = winners[i].GetNumbers();
			cout << "\n\nAposta n�mero: " << winners[i].GetCode();
			cout << "\nApostador: " << tempBettor.GetName() << " - CPF: " << tempBettor.GetCPF();
			cout << "\nN�meros: ";
			for (int j = 0; j < 5; j++) {
				cout << tempArray[j] << " ";
			}
		}
	}

	cout << "\n\nLista de n�meros apostados:\n";
	cout << "N�mero Apostado - Quantidade de apostas\n";
	sort(bettedNumbers.begin(), bettedNumbers.end(), [](const BettedNumberInEdition lhs, const BettedNumberInEdition rhs) {
		return lhs.quantity > rhs.quantity;
	});
	for (int i = 0; i < bettedNumbers.size(); i++) {
		cout << bettedNumbers[i].number << " - " << bettedNumbers[i].quantity << endl;
	}
}

// O m�todo abaixo realiza a fase de premia��o, imprimindo na tela o resultado final.
void Edition::ExecuteAwardPhase() {
	Bettor tempBettor; // Objeto tempor�rio que recebe os apostadores vencedores.

	cout << "\n----------------------Fase de Premia��o---------------------\n";
	if (winners.size() > 0) {
		cout << "\nParab�ns aos ganhadores: \n\n";
		for (int i = 0; i < winners.size(); i++) {
			tempBettor = winners[i].GetBettor();
			cout << tempBettor.GetName() << endl;
		}

		if (winners.size() == 1) {
			cout << "\nO premio de 1.000.000 de reais foi dado ao vencedor.\n";
		} else {
			cout << "\nO pr�mio de 1.000.000 de reais foi dividido entre o(s) " << winners.size() << " vencedores.";
			cout << "\nPremio divido: " << 1000000/ winners.size() << "\n";
		}
	} else {
		cout << "\nN�o houveram vencedores.\n";
	}
}

// O m�todo baixo imprime na tela todas as informa��es da edi��o.
void Edition::ShowEditionData() {
	int* tempArray; // Array tempor�rio que recebe os valores dos n�meros apostados em cada cartilha vencedora.
	Bettor tempBettor; // Objeto tempor�rio que recebe os apostadores vencedores.

	cout << "\nN�mero da edi��o: " << edition_number;
	cout << "\nN�meros vencedores: ";
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
			cout << "\nAposta n�mero: " << winners[i].GetCode();
			cout << "\nApostador: " << tempBettor.GetName() << " - CPF: " << tempBettor.GetCPF();
			cout << "\nN�meros: ";
			for (int j = 0; j < 5; j++) {
				cout << tempArray[j] << " ";
			}
		}
	}

	cout << "\n\nLista de n�meros apostados:\n";
	cout << "\nN�mero Apostado - Quantidade de apostas\n";
	for (int i = 0; i < bettedNumbers.size(); i++) {
		cout << bettedNumbers[i].number << " - " << bettedNumbers[i].quantity << endl;
	}
	cout << "\n------------------------------------------------------------\n";
}