#include "../Header Files/Bet.h"

// Arquivo de implementa��o da Classe Bet.
// Aqui ocorre a implementa��o dos m�todos de mesmo nome declarados e explicados no cabe�alho da classe Bet.

Bet::Bet() {
	code = 0; // Inicializa o atributo com o valor 0.
	memset(numbers, 0, sizeof(numbers)); // Inicializa o atributo numbers com os 5 valores em 0.
}

// Retorna o atributo "code".
int Bet::GetCode() {
	return code;
}
// Recebe por meio do argumento "c" o novo valor do atributo "code".
void Bet::SetCode(int c) {
	code = c;
}

// Retorna o atributo "numbers".
int* Bet::GetNumbers() {
	return numbers;
}
// Recebe por meio do argumento "c", que � um Array, os novos valores do array que forma o atributo "numbers".
void Bet::SetNumbers(int c[5]) {
	for (int i = 0; i < 5; i++) {
		numbers[i] = c[i];
	}
}

/*
No m�todo abaixo � sorteado um n�mero pseudo-aleat�rio entre 1 e 50.
Ent�o � feita uma busca no atributo que representa os n�meros na cartilha para descobrir se o n�mero em quest�o j� foi sorteado.
Caso ele tenha sido sorteado, um novo n�mero � sorteado, se n�o, ele � adicionado como n�mero na cartilha. 
*/
void Bet::SetNumbersRandomly() {
	bool testBool = false; // Variavel para testar a exist�ncia de um n�mero repetido durante o sorteio.
	int number; // Variavel que recebe o n�mero sorteado.

	for (int i = 0; i < 5; i++) {
		testBool = false; 
		while (testBool == false) {
			number = rand() % 50 + 1;

			if (find(begin(numbers), end(numbers), number) == end(numbers)) {
				testBool = true;
			} else {
				testBool = false;
			}

			if (testBool == true) {
				numbers[i] = number;
			}
		}
	}
}

// Retorna o atributo "bettor".
Bettor Bet::GetBettor() {
	return bettor;
}
// Recebe por meio dos argumentos "name" e "cpf", os valores para salvar os dados do atributo "bettor", que � um objeto.
void Bet::SetBettor(string name, string cpf) {
	bettor.SaveBettorData(name, cpf);
}