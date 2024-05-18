#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/set.h"

using namespace std;

const string red = "\033[1;31m";
const string reset = "\033[0m";
const string cyan = "\033[1;36m";

// Recebe a entrada do usuário
string get_input(string line, istringstream& iss) {
    cout << ">>> ";
    getline(cin, line);
    iss = istringstream(line);
    string cmd;
    iss >> cmd;
    return cmd;
}

// Verifica se o índice é inválido
bool invalid_index(unsigned int index, vector<set>& sets) {
    if (index >= sets.size()) {
        cout << endl << red << "Conjunto invalido" << reset << endl;
        return true;
    }
    return false;
}

// Verifica se os argumentos são inválidos
bool invalid_args(istringstream& iss) {
    if (iss.fail()) {
        cout << endl << red << "Argumentos invalidos/insuficientes" << reset << endl;
        return true;
    }

    return false;
}

// Imprime os conjuntos
void print_sets(vector<set>& sets) {
    cout << "Conjuntos:" << endl;
    cout << "-------------------" << endl;
    for (unsigned int i = 0; i < sets.size(); i++) {
        cout << "Conjunto " << i << ": " << sets[i].to_string() << endl;
    }
    cout << "-------------------" << endl;
}