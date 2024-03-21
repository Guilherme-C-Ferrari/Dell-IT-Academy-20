#include "../Header Files/Bookmaker.h"

// Arquivo de implementa��o da Classe Bookmaker.
// Aqui ocorre a implementa��o dos m�todos de mesmo nome declarados e explicados no cabe�alho da classe Bookmaker.

Bookmaker::Bookmaker() {
    editions.resize(0); // Define o tamanho do vetor como 0.
}

// No m�todo abaixo ocorre a inicializa��o que define cores e linguagem ao inicializar o programa, al�m de imprimir uma mensagem inicial.
void Bookmaker::Start() {
    system("Color 09"); // Define a cor das letras e do fundo do console.
	setlocale(LC_ALL, "portuguese"); // Define a linguagem do console.
    srand((unsigned)time(NULL)); // Comando para realiza��o da gera��o de n�meros pseudo-aleat�rios.
    cout << "O programa est� sendo iniciado.\n";
    cout << "Bem-vindo ao sistema de controle de apostas da Dell!\n";
}

// O m�todo abaixo roda o menu do programa.
void Bookmaker::Run() {
    int option = 0; // Vari�vel que recebe as op��es do menu a ser escolhidas.
    int testInt = 0; // Var�avel de apoio Int para teste de Input.
    string testString = ""; // Var�avel de apoio String para teste de Input.

    do {
        testInt = 0;

        cout << "\n---------------------Menu----------------------\n\n";
        cout << "Diga a op��o que deseja:\n\n";
        cout << "1 - Iniciar Edi��o.\n";
        cout << "2 - Checar Edi��es Anteriores.\n";
        cout << "3 - Encerrar programa.\n\n> ";
        cin >> testString;
        option = TestException(testString);
        system("cls");

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
                    system("cls");
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
            cout << endl;
            system("pause"); // Cria uma pausa no console at� que o operador aperte realize um input.
            system("cls"); // Limpa o console.
        }
    } while (option != 3);
}

// O m�todo abaixo finaliza a execu��o do programa.
void Bookmaker::Finish() {
    cout << "\nO programa foi finalizado.\n";
	exit(0);
}

// O m�todo abaixo testa exce��o de input do tipo String onde deveria ser realizada o Input do tipo Int.
int Bookmaker::TestException(string arg_string) {
    int testInt = 0; // Var�avel de apoio Int para teste de Input.
    string testString = arg_string; // Var�avel de apoio String para teste de Input.

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

/*
   O m�todo abaixo cria uma nova edi��o e realiza a ordena��o entre as fases da edi��o.
   No m�todo � utilizado da fun��o Sleep() para deixar a fase de apura��o mais lenta, para no console ela fique
   mais leg�vel e gere a sensa��o de suspense do sorteio dos n�meros estar acontecendo na frente do operador.
*/ 
void Bookmaker::StartNewEdition() {
    bool testBool = false; // Vari�vel que testa o final da fase de apura��o.
    int roundsIndex = 0; // Contador de rodadas realizadas.
    int indexEdition = editions.size(); // �ndice de posi��o da edi��o no vetor.
    editions.resize(indexEdition + 1); // Libera espa�o para uma nova edi��o no vetor.

    editions[indexEdition].SetEditionNumber(editions.size());
    StartBetPhaseOnEdition(indexEdition);
    while (testBool == false && roundsIndex < 25) {
        cout << "\n-----------------------Fase de Sorteio-----------------------\n";
        cout << "\nA fase de sorteio est� sendo executada.\n";
        StartDrawPhaseOnEdtion(indexEdition);
        Sleep(500);
        testBool = StartCoutingPhaseOnEdition(indexEdition);
        roundsIndex++;
        Sleep(1700);
    }
    StartAwardPhaseOnEdition(indexEdition);
}

// O m�todo abaixo serve para iniciar a fase de apostas, lendo os inputs do operador para registrar novas apostas e checar antigas.
void Bookmaker::StartBetPhaseOnEdition(int indexEdition) {
    int option = 0; // Vari�vel que recebe as op��es do menu a ser escolhidas.
    int testInt = 0; // Var�avel de apoio Int para teste de Input. 
    string name = ""; // Var�avel que salva o nome do apostador.
    string cpf = ""; // Var�avel que salva o CPF do apostador.
    string testString = ""; // Var�avel de apoio String para teste de Input.
    bool testBool = false; // Var�avel de apoio Bool para teste de Input.

    do {
        testInt = 0;

        cout << "\n---------------------Fase de Apostas----------------------\n\n";
        cout << "Diga a op��o que deseja:\n\n";
        cout << "1 - Registrar uma aposta.\n";
        cout << "2 - Checar a Lista de Apostas.\n";
        cout << "3 - Passar para a fase de sorteio.\n\n> ";
        cin >> testString;
        option = TestException(testString);
        system("cls");

        switch (option) {
        case 1:
            cout << "\n---------------------Registro de Aposta----------------------\n";
            cout << "Qual o nome do apostador?\n\n";
            cin.ignore();
            getline(cin, name);
            do {
                testBool = false;
                cout << "\nQual o CPF do apostador? Digite apenas os digitos.\n\n";
                cin >> cpf;

                for (int i = 0; i < cpf.size(); i++) {
                    if (isdigit(cpf[i])) {
                        testBool = true;
                    } else {
                        testBool = false;
                    }
                }

                if (testBool == false || size(cpf) != 11) {
                    cout << "\nDigite um valor v�lido.\n";
                }
            } while (testBool == false || size(cpf) != 11);

            do {
                cout << "\nQual forma de registro de aposta deseja fazer?\n";
                cout << "1 - Escolha Manual.\n";
                cout << "2 - Surpresinha. (Escolha Aleat�ria)\n\n> ";
                cin >> testString;
                testInt = TestException(testString);
                if (testInt == 1) {
                    int n[5] = { 0 };
                    for (int i = 0; i < 5; i++) {
                        testBool = false;
                        while (testBool == false) {
                            cout << "\nDigite um valor de 1 a 50, lembresse de digitar um valor diferente dos anteriores.\n\n";
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
                cout << "1 - Sim.\n";
                cout << "2 - N�o.\n\n> ";
                cin >> testString;
                testInt = TestException(testString);

                if (editions[indexEdition].CheckExistenceOfBets() == false) {
                    cout << "\n� necess�rio pelo menos uma aposta registrada para passar para fase de sorteio.\n";
                    testInt = 2;
                }

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
            cout << endl;
            system("pause");
            system("cls");
        }
    } while (option != 3);
}

// O m�todo abaixo inicializa a fase de sorteio chamando o m�todo da edi��o.
void Bookmaker::StartDrawPhaseOnEdtion(int IndexEdition) {
    editions[IndexEdition].ExecuteDrawPhase();
}

// O m�todo abaixo inicializa a fase de apura��o chamando o m�todo da edi��o.
bool Bookmaker::StartCoutingPhaseOnEdition(int IndexEdition) {
    return editions[IndexEdition].ExecuteCoutingPhase();
}

// O m�todo abaixo inicializa a fase de premia��o chamando o m�todo da edi��o.
void Bookmaker::StartAwardPhaseOnEdition(int IndexEdition) {
    editions[IndexEdition].ExecuteAwardPhase();
}

// O m�todo abaixo mostra as edi��es anteriores registradas.
void Bookmaker::CheckPastEditions() {
    cout << "\n---------------------Detalhes das Edi��es----------------------\n";
    if (editions.size() == 0) {
        cout << "\nNenhuma edi��o passada registrada.\n"; // Mensagem caso n�o haja nenhuma edi��o anterior.
    }
    else {
        for (int i = 0; i < editions.size(); i++) {
            editions[i].ShowEditionData();
        }
    }
}