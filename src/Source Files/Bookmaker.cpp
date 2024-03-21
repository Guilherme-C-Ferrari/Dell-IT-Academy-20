#include "../Header Files/Bookmaker.h"

// Arquivo de implementação da Classe Bookmaker.
// Aqui ocorre a implementação dos métodos de mesmo nome declarados e explicados no cabeçalho da classe Bookmaker.

Bookmaker::Bookmaker() {
    editions.resize(0); // Define o tamanho do vetor como 0.
}

// No método abaixo ocorre a inicialização que define cores e linguagem ao inicializar o programa, além de imprimir uma mensagem inicial.
void Bookmaker::Start() {
    system("Color 09"); // Define a cor das letras e do fundo do console.
	setlocale(LC_ALL, "portuguese"); // Define a linguagem do console.
    srand((unsigned)time(NULL)); // Comando para realização da geração de números pseudo-aleatórios.
    cout << "O programa está sendo iniciado.\n";
    cout << "Bem-vindo ao sistema de controle de apostas da Dell!\n";
}

// O método abaixo roda o menu do programa.
void Bookmaker::Run() {
    int option = 0; // Variável que recebe as opções do menu a ser escolhidas.
    int testInt = 0; // Varíavel de apoio Int para teste de Input.
    string testString = ""; // Varíavel de apoio String para teste de Input.

    do {
        testInt = 0;

        cout << "\n---------------------Menu----------------------\n\n";
        cout << "Diga a opção que deseja:\n\n";
        cout << "1 - Iniciar Edição.\n";
        cout << "2 - Checar Edições Anteriores.\n";
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
                cout << "\nVocê tem certeza que deseja encerrar o programa?\n";
                cout << "1 - Sim\n";
                cout << "2 - Não\n\n> ";
                cin >> testString;
                testInt = TestException(testString);

                if (testInt == 1) {
                    system("cls");
                    cout << "\nO programa será finalizado.\n";
                }
                else if (testInt == 2) {
                    cout << "\nO programa voltará ao menu.\n";
                    option = 0;
                }
                else {
                    cout << "\nEscolha uma opção válida.\n";
                }
            } while (testInt != 1 && testInt != 2);
            break;
        default:
            cout << "\nEscolha uma opção válida.\n";
        }
        if (option != 3) {
            cout << endl;
            system("pause"); // Cria uma pausa no console até que o operador aperte realize um input.
            system("cls"); // Limpa o console.
        }
    } while (option != 3);
}

// O método abaixo finaliza a execução do programa.
void Bookmaker::Finish() {
    cout << "\nO programa foi finalizado.\n";
	exit(0);
}

// O método abaixo testa exceção de input do tipo String onde deveria ser realizada o Input do tipo Int.
int Bookmaker::TestException(string arg_string) {
    int testInt = 0; // Varíavel de apoio Int para teste de Input.
    string testString = arg_string; // Varíavel de apoio String para teste de Input.

    try {
       testInt = atoi(testString.c_str());
       if (testInt <= 0) {
           throw (testString);
       }
    } catch (string testString) {
       cout << "\nA opção " << testString << " é inválida.\n";
    }
    return testInt;
}

/*
   O método abaixo cria uma nova edição e realiza a ordenação entre as fases da edição.
   No método é utilizado da função Sleep() para deixar a fase de apuração mais lenta, para no console ela fique
   mais legível e gere a sensação de suspense do sorteio dos números estar acontecendo na frente do operador.
*/ 
void Bookmaker::StartNewEdition() {
    bool testBool = false; // Variável que testa o final da fase de apuração.
    int roundsIndex = 0; // Contador de rodadas realizadas.
    int indexEdition = editions.size(); // Índice de posição da edição no vetor.
    editions.resize(indexEdition + 1); // Libera espaço para uma nova edição no vetor.

    editions[indexEdition].SetEditionNumber(editions.size());
    StartBetPhaseOnEdition(indexEdition);
    while (testBool == false && roundsIndex < 25) {
        cout << "\n-----------------------Fase de Sorteio-----------------------\n";
        cout << "\nA fase de sorteio está sendo executada.\n";
        StartDrawPhaseOnEdtion(indexEdition);
        Sleep(500);
        testBool = StartCoutingPhaseOnEdition(indexEdition);
        roundsIndex++;
        Sleep(1700);
    }
    StartAwardPhaseOnEdition(indexEdition);
}

// O método abaixo serve para iniciar a fase de apostas, lendo os inputs do operador para registrar novas apostas e checar antigas.
void Bookmaker::StartBetPhaseOnEdition(int indexEdition) {
    int option = 0; // Variável que recebe as opções do menu a ser escolhidas.
    int testInt = 0; // Varíavel de apoio Int para teste de Input. 
    string name = ""; // Varíavel que salva o nome do apostador.
    string cpf = ""; // Varíavel que salva o CPF do apostador.
    string testString = ""; // Varíavel de apoio String para teste de Input.
    bool testBool = false; // Varíavel de apoio Bool para teste de Input.

    do {
        testInt = 0;

        cout << "\n---------------------Fase de Apostas----------------------\n\n";
        cout << "Diga a opção que deseja:\n\n";
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
                    cout << "\nDigite um valor válido.\n";
                }
            } while (testBool == false || size(cpf) != 11);

            do {
                cout << "\nQual forma de registro de aposta deseja fazer?\n";
                cout << "1 - Escolha Manual.\n";
                cout << "2 - Surpresinha. (Escolha Aleatória)\n\n> ";
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
                                cout << "\nValor inválido.\n";
                            }
                        }
                    }
                    testInt = 1;
                    editions[indexEdition].RegisterNewBet(name, cpf, 1, n);
                } else if (testInt == 2) {
                    editions[indexEdition].RegisterNewBet(name, cpf, 2, NULL);
                } else {
                    cout << "\nEscolha uma opção válida.\n";
                }
            } while (testInt != 1 && testInt != 2);
            break;
        case 2:
            editions[indexEdition].ShowBets();
            break;
        case 3:
            do {
                cout << "\nVocê tem certeza que deseja passar para a fase de sorteio?\n";
                cout << "1 - Sim.\n";
                cout << "2 - Não.\n\n> ";
                cin >> testString;
                testInt = TestException(testString);

                if (editions[indexEdition].CheckExistenceOfBets() == false) {
                    cout << "\nÉ necessário pelo menos uma aposta registrada para passar para fase de sorteio.\n";
                    testInt = 2;
                }

                if (testInt == 1) {
                    cout << "\nO programa passará para a fase de sorteio.\n";
                }
                else if (testInt == 2) {
                    cout << "\nO programa voltará a fase de apostas.\n";
                    option = 0;
                }
                else {
                    cout << "\nEscolha uma opção válida.\n";
                }
            } while (testInt != 1 && testInt != 2);
            break;
        default:
            cout << "\nEscolha uma opção válida.\n";
        }
        if (option != 3) {
            cout << endl;
            system("pause");
            system("cls");
        }
    } while (option != 3);
}

// O método abaixo inicializa a fase de sorteio chamando o método da edição.
void Bookmaker::StartDrawPhaseOnEdtion(int IndexEdition) {
    editions[IndexEdition].ExecuteDrawPhase();
}

// O método abaixo inicializa a fase de apuração chamando o método da edição.
bool Bookmaker::StartCoutingPhaseOnEdition(int IndexEdition) {
    return editions[IndexEdition].ExecuteCoutingPhase();
}

// O método abaixo inicializa a fase de premiação chamando o método da edição.
void Bookmaker::StartAwardPhaseOnEdition(int IndexEdition) {
    editions[IndexEdition].ExecuteAwardPhase();
}

// O método abaixo mostra as edições anteriores registradas.
void Bookmaker::CheckPastEditions() {
    cout << "\n---------------------Detalhes das Edições----------------------\n";
    if (editions.size() == 0) {
        cout << "\nNenhuma edição passada registrada.\n"; // Mensagem caso não haja nenhuma edição anterior.
    }
    else {
        for (int i = 0; i < editions.size(); i++) {
            editions[i].ShowEditionData();
        }
    }
}