#include "../Header Files/Bookmaker.h"

Bookmaker::Bookmaker() {
    editions.resize(0);
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
    } catch (string testString) {
       cout << "\nA op��o " << testString << " � inv�lida.\n";
    }
    return testInt;
}

void Bookmaker::StartNewEdition() {
    bool testBool = false;
    int index = 0;
    int indexEdition = editions.size();
    editions.resize(indexEdition + 1);

    StartBetPhaseOnEdition(indexEdition);
    while (testBool == false && index < 26) {
        cout << "\n---------------------Fase de Sorteio----------------------\n";
        cout << "A fase de sorteio est� sendo executada.\n";
        StartDrawPhaseOnEdtion(indexEdition);
        testBool = StartCoutingPhaseOnEdition(indexEdition);

        index++;
    }
    StartAwardPhaseOnEdition(indexEdition);
}

void Bookmaker::StartBetPhaseOnEdition(int indexEdition) {
    int option = 0;
    int testInt = 0;
    string testString = "";
    string name = "";
    string cpf = "";
    bool testBool = false;

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
                    for (int i = 0; i < 5; i++) {
                        testBool = false;
                        while (testBool == false) {
                            cout << "\nDigite um valor de 1 a 50, lembresse de digitar um valor diferentes dos anteriores\n\n";
                            cin >> testString;
                            testInt = TestException(testString);

                            if (find(begin(n), end(n), testInt) == end(n) && testInt >= 1 && testInt <= 50) {
                                testBool = true;
                            } else {
                                testBool = false;
                            }

                            if (testBool == true) {
                                n[i] = testInt;
                            } else {
                                cout << "\nValor inv�lido.\n";
                            }
                        }
                    }
                    testInt = 1;
                    editions[indexEdition].RegisterNewBet(name, cpf, 1, n);
                } else if (testInt == 2) {
                    editions[indexEdition].RegisterNewBet(name, cpf, 2, NULL);
                } else {
                    cout << "\nEscolha uma op��o v�lida.\n";
                }
            } while (testInt != 1 && testInt != 2);
            break;
        case 2:
            editions[indexEdition].ShowBets();
            break;
        case 3:
            do {
                cout << "\nVoc� tem certeza que deseja passar para a fase de sorteio?\n";
                cout << "1 - Sim\n";
                cout << "2 - N�o\n\n> ";
                cin >> testString;
                testInt = TestException(testString);

                if (testInt == 1) {
                    cout << "\nO programa passar� para a fase de sorteio.\n";
                }
                else if (testInt == 2) {
                    cout << "\nO programa voltar� a fase de apostas.\n";
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

void Bookmaker::StartDrawPhaseOnEdtion(int IndexEdition) {
    editions[IndexEdition].ExecuteDrawPhase();
}

bool Bookmaker::StartCoutingPhaseOnEdition(int IndexEdition) {
    return editions[IndexEdition].ExecuteCoutingPhase();
}

void Bookmaker::StartAwardPhaseOnEdition(int IndexEdition) {
    editions[IndexEdition].ExecuteAwardPhase();
}

void Bookmaker::CheckPastEditions() {
    for (int i = 0; i < editions.size(); i++) {
        editions[i].ShowEditionData();
    }
}