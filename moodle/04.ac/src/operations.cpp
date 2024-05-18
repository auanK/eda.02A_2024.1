#pragma once

#include "utils.cpp"

using namespace std;

void create(vector<set>& sets) {
    sets.push_back(set());
    cout << endl
         << cyan << "O conjunto " << sets.size() - 1 << " foi criado" << reset
         << endl;
}

void insert(istringstream& iss, vector<set>& sets) {
    int index, key;
    iss >> index >> key;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    while (iss) {
        sets[index].insert(key);
        iss >> key;
        if (iss.fail()) {
            break;
        }
    }

    cout << endl
         << cyan << "Elemento(s) inserido(s) com sucesso" << reset << endl;
}

void show(istringstream& iss, vector<set>& sets) {
    int index;
    iss >> index;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    cout << endl;
    sets[index].print_tree();
    cout << endl;
}

void erase(istringstream& iss, vector<set>& sets) {
    int index, key;
    iss >> index >> key;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    try {
        sets[index].erase(key);
        cout << endl
             << cyan << "Elemento removido com sucesso" << reset << endl;
    } catch (const runtime_error& e) {
        cout << red << endl << e.what() << reset << endl;
    }
}

void contains(istringstream& iss, vector<set>& sets) {
    int index, key;
    iss >> index >> key;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    cout << endl << "O conjunto " << index << " ";
    cout << (sets[index].contains(key) ? cyan + "contem "
                                       : red + "nao contem ");
    cout << reset << "a chave " << key << endl;
}

void clear(istringstream& iss, vector<set>& sets) {
    int index;
    iss >> index;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    sets[index].clear();
    cout << endl << cyan << "Conjunto limpo com sucesso" << reset << endl;
}

void del(istringstream& iss, vector<set>& sets) {
    int index;
    iss >> index;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    sets.erase(sets.begin() + index);
    cout << endl << cyan << "Conjunto deletado com sucesso" << reset << endl;
}

void swap(istringstream& iss, vector<set>& sets) {
    int index1, index2;
    iss >> index1 >> index2;

    if (invalid_args(iss) || invalid_index(index1, sets) ||
        invalid_index(index2, sets)) {
        return;
    }

    swap(sets[index1], sets[index2]);
    cout << endl
         << cyan << "Os conjuntos " << index1 << " e " << index2
         << " foram trocados" << reset << endl;
}

void min(istringstream& iss, vector<set>& sets) {
    int index;
    iss >> index;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    try {
        int min = sets[index].minimum();
        cout << endl
             << cyan << "O menor elemento do conjunto " << index << " e " << min
             << reset << endl;
    } catch (const runtime_error& e) {
        cout << endl << red << e.what() << reset << endl;
    }
}

void max(istringstream& iss, vector<set>& sets) {
    int index;
    iss >> index;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    try {
        int max = sets[index].maximum();
        cout << endl
             << cyan << "O maior elemento do conjunto " << index << " e " << max
             << reset << endl;
    } catch (const runtime_error& e) {
        cout << endl << red << e.what() << reset << endl;
    }
}

void succ(istringstream& iss, vector<set>& sets) {
    int index, key;
    iss >> index >> key;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    cout << endl;
    try {
        int succ = sets[index].successor(key);
        cout << cyan << "O sucessor de " << key << " no conjunto " << index
             << " e " << succ << reset << endl;
    } catch (const runtime_error& e) {
        cout << red << e.what() << reset << endl;
    }
}

void pred(istringstream& iss, vector<set>& sets) {
    int index, key;
    iss >> index >> key;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    cout << endl;
    try {
        int pred = sets[index].predecessor(key);
        cout << cyan << "O predecessor de " << key << " no conjunto " << index
             << " e " << pred << reset << endl;
    } catch (const runtime_error& e) {
        cout << red << e.what() << reset << endl;
    }
}

void empty(istringstream& iss, vector<set>& sets) {
    int index;
    iss >> index;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    cout << endl << "O conjunto " << index << " ";
    cout << (sets[index].empty() ? cyan + "esta vazio"
                                 : red + "nao esta vazio");
    cout << reset << endl;
}

void size(istringstream& iss, vector<set>& sets) {
    int index;
    iss >> index;

    if (invalid_args(iss) || invalid_index(index, sets)) {
        return;
    }

    cout << endl
         << cyan << "O conjunto " << index << " tem tamanho "
         << sets[index].size() << reset << endl;
}

void uni(istringstream& iss, vector<set>& sets) {
    int i, j;
    iss >> i >> j;

    if (invalid_args(iss) || invalid_index(i, sets) || invalid_index(j, sets) ||
        i == j) {
        return;
    }

    sets.push_back(sets[i].union_set(sets[j]));
    cout << endl
         << cyan << "O conjunto " << sets.size() - 1
         << " foi criado com a uniao dos conjuntos " << i << " e " << j << reset
         << endl;
}

void inter(istringstream& iss, vector<set>& sets) {
    int i, j;
    iss >> i >> j;

    if (invalid_args(iss) || invalid_index(i, sets) || invalid_index(j, sets) ||
        i == j) {
        return;
    }

    sets.push_back(sets[i].intersection_set(sets[j]));
    cout << endl
         << cyan << "O conjunto " << sets.size() - 1
         << " foi criado com a intersecao dos conjuntos " << i << " e " << j
         << reset << endl;
}

void diff(istringstream& iss, vector<set>& sets) {
    int i, j;
    iss >> i >> j;

    if (invalid_args(iss) || invalid_index(i, sets) || invalid_index(j, sets) ||
        i == j) {
        return;
    }

    sets.push_back(sets[i].difference_set(sets[j]));
    cout << endl
         << cyan << "O conjunto " << sets.size() - 1
         << " foi criado com a diferenca dos conjuntos " << i << " e " << j
         << reset << endl;
}

void help() {
    cout << "Comandos:" << endl;
    cout << " create - Cria um novo conjunto vazio" << endl;
    cout << " insert <i> <key> <key> ... - Insere elementos em um conjunto"
         << endl;
    cout << " erase <i> <key> - Remove um elemento do conjunto" << endl;
    cout << " show <i> - Imprime os elementos de um conjunto em forma de árvore"
         << endl;
    cout << " contains <i> <key> - Verifica se uma chave pertence ao conjunto"
         << endl;
    cout << " clear <i> - Remove todos os elementos de um conjunto" << endl;
    cout << " size <i> - Mostra o tamanho de um conjunto" << endl;
    cout << " del <i> - Deleta um conjunto" << endl;
    cout << " swap <i> <j> - Troca os elementos de dois conjuntos" << endl;
    cout << " min <i> - Mostra o menor elemento do conjunto" << endl;
    cout << " max <i> - Mostra o maior elemento do conjunto" << endl;
    cout << " succ <i> <key> - Mostra o sucessor de uma chave no conjunto"
         << endl;
    cout << " pred <i> <key> - Mostra o predecessor de uma chave no "
            "conjunto"
         << endl;
    cout << " empty <i> - Verifica se o conjunto está vazio" << endl;
    cout << " size <i> - Mostra o tamanho de um conjunto" << endl;
    cout << " union <i> <j> - Cria um conjunto com a união dos conjuntos de "
            "dois conjuntos"
         << endl;
    cout << " inter <i> <j> - Cria um conjunto com a interseção de dois "
            "conjuntos"
         << endl;
    cout << " diff <i> <j> - Cria um conjunto com a diferença de dois "
            "conjuntos"
         << endl;
    cout << " exit - Sai do programa" << endl;
    cout << " help - Mostra esta mensagem" << endl;
    cout << endl;
}
