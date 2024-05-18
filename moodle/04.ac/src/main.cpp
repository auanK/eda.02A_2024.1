#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/set.h"
#include "operations.cpp"
#include "utils.cpp"

using namespace std;

int main() {
    cout << "digite help para ver os comandos" << endl << endl;
    string line = "";
    istringstream iss = istringstream();
    vector<set> sets = vector<set>();

    while (true) {
        print_sets(sets);

        string cmd = get_input(line, iss);

        // Cria um novo conjunto
        if (cmd == "create") {
            create(sets);    
        }

        // Insere elementos em um conjunto
        else if (cmd == "insert") {
            insert(iss, sets);
        }

        // Imprime um conjunto em forma de árvore
        else if (cmd == "show") {
            show(iss, sets);
        }

        // Remove um elemento do conjunto
        else if (cmd == "erase") {
            erase(iss, sets);
        }

        // Verifica se o conjunto contém um elemento
        else if (cmd == "contains") {
            contains(iss, sets);
        }

        // Limpa um conjunto
        else if (cmd == "clear") {
            clear(iss, sets);
        }

        // Mostra o tamanho de um conjunto
        else if (cmd == "size") {
            size(iss, sets);
        }

        // Remove um conjunto
        else if (cmd == "del") {
            del(iss, sets);
        }

        // Troca o conteúdo de dois conjuntos
        else if (cmd == "swap") {
            swap(iss, sets);
        }

        // Mostra o menor elemento de um conjunto
        else if (cmd == "min") {
            min(iss, sets);
        }

        // Mostra o maior elemento de um conjunto
        else if (cmd == "max") {
            max(iss, sets);
        }

        // Mostra o sucessor de um elemento em um conjunto
        else if (cmd == "succ") {
            succ(iss, sets);
        }

        // Mostra o predecessor de um elemento em um conjunto
        else if (cmd == "pred") {
            pred(iss, sets);
        }

        // Verifica se um conjunto está vazio
        else if (cmd == "empty") {
            empty(iss, sets);
        }

        // Faz a união de dois conjuntos
        else if (cmd == "union") {
            uni(iss, sets);
        }

        // Faz a interseção de dois conjuntos
        else if (cmd == "inter") {
            inter(iss, sets);
        }

        // Faz a diferença de dois conjuntos
        else if (cmd == "diff") {
            diff(iss, sets);
        }

        // Mostra os comandos disponíveis
        else if (cmd == "help") {
            help();
        }

        // Sai do programa
        else if (cmd == "exit") {
            cout << "Saindo..." << endl;
            break;
        }

        else {
            cout << red << endl << "Comando invalido" << reset << endl;
        }
        cout << endl;
    }

    return 0;
}
