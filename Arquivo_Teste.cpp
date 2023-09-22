#include <iostream>
#include <string>
#include <locale.h>
#define MAX_FILA 5
using namespace std;

struct DADOS_ALUNO {
    int codaluno;
    string nome;
    char turma;
    bool removido;
    float nota;
};

bool enfileirar(DADOS_ALUNO fila[], int codaluno, const string& nome, char turma, float nota, int& fimfila, int& totalfila);
bool exibir(DADOS_ALUNO fila[], int inifila, int totalfila);
bool desenfileirar(DADOS_ALUNO fila[], int& inifila, int& totalfila);
bool exibirturmaA(DADOS_ALUNO fila[], int totalfila);
bool exibirturmaB(DADOS_ALUNO fila[], int totalfila);
bool medianotaA(DADOS_ALUNO fila[], int totalfila);
bool medianotaB(DADOS_ALUNO fila[], int totalfila);
bool maiornota(DADOS_ALUNO fila[], int totalfila);
bool menornota(DADOS_ALUNO fila[], int totalfila);

int main() {
    setlocale(LC_ALL, "Portuguese");
    DADOS_ALUNO filaaluno[MAX_FILA];
    int inifila = 0;
    int totalfila = 0;
    int fimfila = 0;
    bool ret;
    int codaluno;
    int opcao;
    string nome;
    char turma;
    float nota;

    do {
        cout << "\n1 - Enfileirar";
        cout << "\n2 - Exibir";
        cout << "\n3 - Desenfileirar";
        cout << "\n4 - Exibir alunos da Turma A";
        cout << "\n5 - Exibir alunos da Turma B";
        cout << "\n6 - Exibir média das notas dos alunos da Turma A";
        cout << "\n7 - Exibir média das notas dos alunos da Turma B";
        cout << "\n8 - Exibir maior nota geral entre as Turmas A e B";
        cout << "\n9 - Exibir menor nota geral entre as Turmas A e B";
        cout << "\n10 - Sair";
        cout << "\nDigite a opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Inserção" << endl;
                cout << "Digite o código do aluno: ";
                cin >> codaluno;
                cout << "Digite o nome do aluno: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite a turma do aluno (A ou B): ";
                cin >> turma;
                cout << "Digite a nota do aluno: ";
                cin >> nota;
                ret = enfileirar(filaaluno, codaluno, nome, turma, nota, fimfila, totalfila);
                if (ret == true) {
                    cout << "\nInserção feita com sucesso!" << endl;
                }
                break;

            case 2:
                ret = exibir(filaaluno, inifila, totalfila);
                if (ret == false) {
                    cout << "\nNão foi possivel exibir a fila" << endl;
                }
                break;

            case 3:
                ret = desenfileirar(filaaluno, inifila, totalfila);
                if (ret == false) {
                    cout << "\nNão foi possivel desenfileirar a fila" << endl;
                }
                break;

            case 4:
                ret = exibirturmaA(filaaluno, totalfila);
                if (ret == false) {
                    cout << "\nNão foi possivel exibir a turmaA" << endl;
                }
                break;

            case 5:
                ret = exibirturmaB(filaaluno, totalfila);
                if (ret == false) {
                    cout << "\nNão foi possivel exibir a turmaB" << endl;
                }
                break;

            case 6:
                ret = medianotaA(filaaluno, totalfila);
                if (ret == false) {
                    cout << "\nNão foi possivel exibir a média das notas da turma A" << endl;
                }
                break;

            case 7:
                ret = medianotaB(filaaluno, totalfila);
                if (ret == false) {
                    cout << "\nNão foi possivel exibir a média das notas da turma B" << endl;
                }
                break;

            case 8:
                ret = maiornota(filaaluno, totalfila);
                if (ret == false) {
                    cout << "\nNão foi possivel exibir a maior nota das turmas" << endl;
                }
                break;

            case 9:
                ret = menornota(filaaluno, totalfila);
                if (ret == false) {
                    cout << "\nNão foi possivel exibir a menor nota das turmas" << endl;
                }
                break;

            case 10:
                cout << "Saindo do programa!";
                break;

            default:
                cout << "\nERRO: A opção digitada não é válida. Tente novamente..." << endl;
        }
    } while (opcao != 10);

    return 0;
}

bool enfileirar(DADOS_ALUNO fila[], int codaluno, const string& nome, char turma, float nota, int& fimfila, int& totalfila) {
    if (totalfila == MAX_FILA) {
        cout << "\nA fila está cheia." << endl;
        return false;
    }

    fila[fimfila].codaluno = codaluno;
    fila[fimfila].nome = nome;
    fila[fimfila].turma = turma;
    fila[fimfila].nota = nota;
    fila[fimfila].removido = false;

    fimfila = (fimfila + 1) % MAX_FILA; // Circular
    totalfila++;

    return true;
}

bool exibir(DADOS_ALUNO fila[], int inifila, int totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila está vazia." << endl;
        return false;
    }

    int index = inifila;
    for (int i = 0; i < totalfila; i++) {
        if (!fila[index].removido) {
            cout << "Código: " << fila[index].codaluno << ", Nome: " << fila[index].nome << ", Turma: " << fila[index].turma << ", Nota: " << fila[index].nota << endl;
        }
        index = (index + 1) % MAX_FILA;
    }

    return true;
}

bool desenfileirar(DADOS_ALUNO fila[], int& inifila, int& totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila está vazia." << endl;
        return false;
    }

    fila[inifila].removido = true;
    inifila = (inifila + 1) % MAX_FILA; // Circular
    totalfila--;

    return true;
}

bool exibirturmaA(DADOS_ALUNO fila[], int totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila está vazia." << endl;
        return false;
    }

    for (int i = 0; i < totalfila; i++) {
        if (!fila[i].removido && fila[i].turma == 'A') {
            cout << "Cádigo: " << fila[i].codaluno << ", Nome: " << fila[i].nome << ", Turma: " << fila[i].turma << ", Nota: " << fila[i].nota << endl;
        }
    }

    return true;
}

bool exibirturmaB(DADOS_ALUNO fila[], int totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila está vazia." << endl;
        return false;
    }

    for (int i = 0; i < totalfila; i++) {
        if (!fila[i].removido && fila[i].turma == 'B') {
            cout << "Código: " << fila[i].codaluno << ", Nome: " << fila[i].nome << ", Turma: " << fila[i].turma << ", Nota: " << fila[i].nota << endl;
        }
    }

    return true;
}

bool medianotaA(DADOS_ALUNO fila[], int totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila está vazia." << endl;
        return false;
    }

    float soma = 0;
    int contador = 0;

    for (int i = 0; i < totalfila; i++) {
        if (!fila[i].removido && fila[i].turma == 'A') {
            soma += fila[i].nota;
            contador++;
        }
    }

    if (contador > 0) {
        float media = soma / contador;
        cout << "Média das notas da Turma A: " << media << endl;
    } else {
        cout << "Nenhum aluno na Turma A encontrado." << endl;
    }

    return true;
}

bool medianotaB(DADOS_ALUNO fila[], int totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila está vazia." << endl;
        return false;
    }

    float soma = 0;
    int contador = 0;

    for (int i = 0; i < totalfila; i++) {
        if (!fila[i].removido && fila[i].turma == 'B') {
            soma += fila[i].nota;
            contador++;
        }
    }

    if (contador > 0) {
        float media = soma / contador;
        cout << "Média das notas da Turma B: " << media << endl;
    } else {
        cout << "Nenhum aluno na Turma B encontrado." << endl;
    }

    return true;
}

bool maiornota(DADOS_ALUNO fila[], int totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila está vazia." << endl;
        return false;
    }

    float maiorNota = fila[0].nota;

    for (int i = 0; i < totalfila; i++) {
        if (!fila[i].removido && fila[i].nota > maiorNota) {
            maiorNota = fila[i].nota;
        }
    }

    cout << "Maior nota entre as Turmas A e B: " << maiorNota << endl;
    return true;
}

bool menornota(DADOS_ALUNO fila[], int totalfila) {
    if (totalfila == 0) {
        cout << "\nA fila está vazia." << endl;
        return false;
    }

    float menorNota = fila[0].nota;

    for (int i = 0; i < totalfila; i++) {
        if (!fila[i].removido && fila[i].nota < menorNota) {
            menorNota = fila[i].nota;
        }
    }

    cout << "Menor nota entre as Turmas A e B: " << menorNota << endl;
    return true;
}
