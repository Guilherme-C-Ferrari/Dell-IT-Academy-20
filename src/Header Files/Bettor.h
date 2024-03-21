#pragma once
# include <iostream>
# include <algorithm>
# include <cstdlib>
# include <stdlib.h>
# include <string>
# include <time.h>
# include <vector>
# include <windows.h>
using namespace std;

// Arquivo de Cabeçalho da Classe Bettor.
// A Classe Bettor abaixo representa os apostadores que apostarão no sistema.

class Bettor {

private:

	string name; // Atributo que representa o nome do apostador.
	string cpf; // Atributo que representa o CPF do apostador.

public:
	// Construtor da Classe Bettor.
	Bettor();

	// Getters e Setters do atributo "name".
	string GetName();
	void SetName(string n);

	// Getters e Setters do atributo "cpf".
	string GetCPF();
	void SetCPF(string c);

	// Método para receber e salvar os dados dos dois atributos do apostador.
	void SaveBettorData(string n, string c);
};