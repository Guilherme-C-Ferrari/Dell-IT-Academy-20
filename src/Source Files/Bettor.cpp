# include "../Header Files/Bettor.h";

Bettor::Bettor() {
	name = "";
	cpf = "";
}

string Bettor::GetName() {
	return name;
}

void Bettor::SetName(string n) {
	name = n;
}

string Bettor::GetCPF() {
	return cpf;
}

void Bettor::SetCPF(string c) {
	cpf = c;
}

void Bettor::SaveBettorData(string n, string c) {
	SetName(n);
	SetCPF(c);
}