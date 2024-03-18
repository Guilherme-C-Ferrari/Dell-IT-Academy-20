#include "../Header Files/Bookmaker.h"

Bookmaker::Bookmaker() {
    editions = vector<Edition>(0);
}

void Bookmaker::Start() {
	setlocale(LC_ALL, "portuguese");
    srand((unsigned)time(NULL));
    cout << "O programa est� sendo iniciado.\n";
}

void Bookmaker::Run() {
    int option = 0;
    int testInt = 0;
    string testString = "";

    do {
        testInt = 0;

        cout << "\n---------------------Menu----------------------\n\n";
        cout << "Diga a op��o que deseja:\n\n";
        cout << "1 - Iniciar Edi��o\n";
        cout << "2 - Checar Edi��es Anteriores\n";
        cout << "3 - Encerrar programa\n\n> ";
        cin >> testString;
        option = TestException(testString);

        switch (option) {
        case 1:
            StartNewEdition();
            break;
        case 2:
            CheckPastEditions();
            break;
        case 3:
            do {
                cout << "\nVoc� tem certeza que deseja encerrar o programa?\n";
                cout << "1 - Sim\n";
                cout << "2 - N�o\n\n> ";
                cin >> testString;
                testInt = TestException(testString);

                if (testInt == 1) {
                    cout << "\nO programa ser� finalizado.\n";
                }
                else if (testInt == 2) {
                    cout << "\nO programa voltar� ao menu.\n";
                    option = 0;
                }
                else {
                    cout << "\nEscolha uma op��o v�lida.\n";
                }
            } while (testInt != 1 && testInt != 2);
            break;
        default:
            cout << "\nEscolha uma op��o v�lida.\n";
        }
        if (option != 3) {
            cout << "\nPressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (option != 3);
}

void Bookmaker::Finish() {
    cout << "\nO programa foi finalizado.\n";
	exit(0);
}

int Bookmaker::TestException(string arg_string) {
    int testInt = 0;
    string testString = arg_string;

    try {
        testInt = atoi(testString.c_str());
        if (testInt <= 0) {
            throw (testString);
        }
    }
    catch (string testString) {
        cout << "\nA op��o " << testString << " � inv�lida.\n";
    }
    return testInt;
}

void Bookmaker::StartNewEdition() {
    int indexEdition = editions.size();
    editions.resize(indexEdition + 1);

    StartBetPhaseOnEdition(indexEdition);
}

void Bookmaker::StartBetPhaseOnEdition(int indexEdition) {
    int option = 0;
    int testInt = 0;
    string testString = "";
    string name = "";
    string cpf = "";

    do {
        testInt = 0;

        cout << "\n---------------------Fase de Apostas----------------------\n\n";
        cout << "Diga a op��o que deseja:\n\n";
        cout << "1 - Registrar uma aposta\n";
        cout << "2 - Checar a Lista de Apostas\n";
        cout << "3 - Passar para a fase de sorteio\n\n> ";
        cin >> testString;
        option = TestException(testString);

        switch (option) {
        case 1:
            cout << "\n---------------------Registro de Aposta----------------------\n";
            cout << "Qual o nome do apostador?\n\n";
            cin >> name;
            cout << "\nQual o cpf do apostador?\n\n";
            cin >> cpf;

            do {
                cout << "\nQual forma de registro de aposta deseja fazer?\n";
                cout << "1 - Escolha Manual\n";
                cout << "2 - Surpresinha (Escolha Aleat�ria)\n\n> ";
                cin >> testString;
                testInt = TestException(testString);
                if (testInt == 1) {
                    int n[5] = { 0 };

                    editions[indexEdition].RegisterNewBet(name, cpf, 1, n);
                }
                else if (testInt == 2) {
                    editions[indexEdition].RegisterNewBet(name, cpf, 2, NULL);
                }
                else {
                    cout << "\nEscolha uma op��o v�lida.\n";
                }
            } while (testInt != 1 && testInt != 2);
            break;
        case 2:
            editions[indexEdition].ShowBets();
            break;
        case 3:
            cout << "\nO programa seguir� para a fase de sorteio?\n";
            break;
        default:
            cout << "\nEscolha uma op��o v�lida.\n";
        }
        if (option != 3) {
            cout << "\nPressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (option != 3);
}

void Bookmaker::StartDrawPhaseOnEdtion(int IndexEdition) {

}

void Bookmaker::StartCoutingPhaseOnEdition(int IndexEdition) {

}

void Bookmaker::StartAwardPhaseOnEdition(int IndexEdition) {

}

void Bookmaker::CheckPastEditions() {

}