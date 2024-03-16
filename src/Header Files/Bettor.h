#pragma once
# include <iostream>
using namespace std;

class Bettor {

private:

	string name;
	string cpf;

public:

	Bettor();

	string GetName();
	void SetName(string n);

	string GetCPF();
	void SetCPF(string c);

	void SaveBettorData(string n, string c);

};