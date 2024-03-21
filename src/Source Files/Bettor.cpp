# include "../Header Files/Bettor.h"

// Arquivo de implementa��o da Classe Bettor.
// Aqui ocorre a implementa��o dos m�todos de mesmo nome declarados e explicados no cabe�alho da classe Bettor.

Bettor::Bettor() {
	name = ""; // Inicializa o atributo como uma String vazia.
	cpf = ""; // Inicializa o atributo como uma String vazia.
}

// Retorna o atributo "name".
string Bettor::GetName() {
	return name;
}
// Recebe por meio do argumento "n" o novo valor do atributo "name".
void Bettor::SetName(string n) {
	name = n;
}

// Retorna o atributo "cpf". 
string Bettor::GetCPF() {
	return cpf;
}
// Recebe por meio do argumento "c" o novo valor do atributo "cpf".
void Bettor::SetCPF(string c) {
	cpf = c;
}

// Recebe por meio dos argumentos "n" e "c" dois valores, e ap�s isso chama as fun��es Set dos atributos "name" e "cpf"
void Bettor::SaveBettorData(string n, string c) {
	SetName(n);
	SetCPF(c);
}