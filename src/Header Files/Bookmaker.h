#pragma once
# include "Edition.h"

class Bookmaker {

private:

	vector<Edition> Editions;

public:

	Bookmaker();

	// M�todo que inicializa o programa
	void Start();

	// M�todo que roda o programa, onde fica o menu que ser� usado pelo usu�rio para acessar as funcionalidades
	void Run();

	// M�todo que finaliza o programa
	void Finish();
};