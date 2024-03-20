#include "../Header Files/Bet.h"

// Arquivo de implementação da Classe Bet.
// Aqui ocorre a implementação dos métodos de mesmo nome declarados e explicados no cabeçalho da classe Bet.

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
// Recebe por meio do argumento "c", que é um Array, os novos valores do array que forma o atributo "numbers".
void Bet::SetNumbers(int c[5]) {
	for (int i = 0; i < 5; i++) {
		numbers[i] = c[i];
	}
}

/*
No método abaixo é sorteado um número pseudo-aleatório entre 1 e 50.
Então é feita uma busca no atributo que representa os números na cartilha para descobrir se o número em questão já foi sorteado.
Caso ele tenha sido sorteado, um novo número é sorteado, se não, ele é adicionado como número na cartilha. 
*/
void Bet::SetNumbersRandomly() {
	bool testBool = false; // Variavel para testar a existência de um número repetido durante o sorteio.
	int number; // Variavel que recebe o número sorteado.

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
// Recebe por meio dos argumentos "name" e "cpf", os valores para salvar os dados do atributo "bettor", que é um objeto.
void Bet::SetBettor(string name, string cpf) {
	bettor.SaveBettorData(name, cpf);
}