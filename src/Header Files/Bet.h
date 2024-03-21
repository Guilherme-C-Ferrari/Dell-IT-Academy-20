#pragma once
# include "Bettor.h"

// Arquivo de Cabe�alho da Classe Bet.
// A Classe Bet abaixo representa as cartilhas de apostas feitas no sistema.

class Bet {

private:

	int code; // Atributo que representa o c�digo da cartilha que � �nico em cada edi��o.
	int numbers[5]; // Atributo que representa os cinco n�meros presentes na cartilha de aposta.
	Bettor bettor; // Atributo que representa o apostador relacionado a cartilha, nesse caso, aquele que a possui.

public: 
	// Construtor da Classe Bet.
	Bet();

	// Getters e Setters do atributo "code".
	int GetCode();
	void SetCode(int c);

	/*
	Getters e Setters do atributo "numbers".
	Aqui existem dois Setters diferentes para o atributo, visto que o primeiro recebe os n�meros definidos manualmente 
	pelo apostador na forma de um Array e o outro define eles aleat�riamente.
	*/
	int* GetNumbers();
	void SetNumbers(int c[5]);
	void SetNumbersRandomly();

	// Getters e Setters do atributo "bettor", que relaciona um apostador a cartilha.
	Bettor GetBettor();
	void SetBettor(string name, string cpf);
};