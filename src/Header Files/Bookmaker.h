#pragma once
# include "Edition.h"

class Bookmaker {

private:

	vector<Edition> Editions;

public:

	Bookmaker();

	// Método que inicializa o programa
	void Start();

	// Método que roda o programa, onde fica o menu que será usado pelo usuário para acessar as funcionalidades
	void Run();

	// Método que finaliza o programa
	void Finish();
};