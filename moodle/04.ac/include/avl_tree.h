#pragma once

#include <iostream>
#include <string>

#include "node.h"

class avl_tree {
   private:
    node* _root = nullptr;
    unsigned int _size = 0;

    node* _copy(node* other_root) {
        if (other_root == nullptr) {
            return nullptr;
        }
        node* new_node =
            new node(other_root->key, other_root->height, nullptr, nullptr);
        new_node->left = _copy(other_root->left);
        new_node->right = _copy(other_root->right);
        return new_node;
    }

    int _height(node* n) {
        if (n == nullptr) {
            return 0;
        }
        return n->height;
    }

    int _balance(node* n) { 
        return _height(n->right) - _height(n->left); 
    }

    node* _right_rotation(node* p) {
        node* u = p->left;
        p->left = u->right;
        u->right = p;

        p->height = 1 + std::max(_height(p->left), _height(p->right));
        u->height = 1 + std::max(_height(u->left), _height(u->right));

        return u;
    }

    node* _left_rotation(node* p) {
        node* u = p->right;
        p->right = u->left;
        u->left = p;

        p->height = 1 + std::max(_height(p->left), _height(p->right));
        u->height = 1 + std::max(_height(u->left), _height(u->right));

        return u;
    }

    node* _insert(node* p, int key) {
        if (p == nullptr) {
            _size++;
            return new node{key, 1, nullptr, nullptr};
        }
        if (key == p->key) {
            return p;
        }
        if (key < p->key) {
            p->left = _insert(p->left, key);
        } else {
            p->right = _insert(p->right, key);
        }

        p = _fixup_node(p, key);
        return p;
    }

    node* _fixup_node(node* p, int key) {
        p->height = 1 + std::max(_height(p->left), _height(p->right));

        int bal = _balance(p);

        if (bal < -1 && key < p->left->key)
            return _right_rotation(p);
        else if (bal < -1 && key > p->left->key) {
            p->left = _left_rotation(p->left);
            return _right_rotation(p);
        }

        else if (bal > 1 && key > p->right->key)
            return _left_rotation(p);

        else if (bal > 1 && key < p->right->key) {
            p->right = _right_rotation(p->right);
            return _left_rotation(p);
        }
        return p;
    }

    node* _remove(node* n, int key) {
        if (n == nullptr) {
            return nullptr;
        }

        if (key < n->key) {
            n->left = _remove(n->left, key);
        } else if (key > n->key) {
            n->right = _remove(n->right, key);
        } else if (n->right == nullptr) {
            node* temp = n->left;
            delete n;
            _size--;
            return temp;
        } else {
            n->right = _remove_successor(n, n->right);
            _size--;
        }

        n = _fixup_deletion(n);

        return n;
    }

    node* _remove_successor(node* n, node* successor) {
        if (successor->left != nullptr) {
            successor->left = _remove_successor(n, successor->left);
        } else {
            n->key = successor->key;
            node* temp = successor->right;
            delete successor;
            return temp;
        }
        successor = _fixup_deletion(successor);
        return successor;
    }

    node* _fixup_deletion(node* n) {
        if (n == nullptr) {
            return nullptr;
        }
        n->height = 1 + std::max(_height(n->left), _height(n->right));

        int bal = _balance(n);

        if (bal > 1 && _balance(n->right) >= 0)
            return _left_rotation(n);

        else if (bal > 1 && _balance(n->right) < 0) {
            n->right = _right_rotation(n->right);
            return _left_rotation(n);
        }

        else if (bal < -1 && _balance(n->left) <= 0)
            return _right_rotation(n);

        else if (bal < -1 && _balance(n->left) > 0) {
            n->left = _left_rotation(n->left);
            return _right_rotation(n);
        }

        return n;
    }

    node* _search(node* n, int key) {
        if (n == nullptr) {
            return nullptr;
        }

        if (n->key == key) {
            return n;
        }

        if (key < n->key) {
            return _search(n->left, key);
        }
        return _search(n->right, key);
    }

    node* _minimum(node* n) {
        if (n == nullptr) {
            return nullptr;
        }

        while (n->left != nullptr) {
            n = n->left;
        }

        return n;
    }

    node* _maximum(node* n) {
        if (n == nullptr) {
            return nullptr;
        }

        while (n->right != nullptr) {
            n = n->right;
        }

        return n;
    }

    node* _successor(node* n, node* succ, int key) {
        if (n == nullptr) {
            if (succ == nullptr) {
                return nullptr;
            }
            return succ;
        }

        if (n->key > key) {
            return _successor(n->left, n, key);
        }
        return _successor(n->right, succ, key);
    }

    node* _predecessor(node* n, node* pred, int key) {
        if (n == nullptr) {
            if (pred == nullptr) {
                return nullptr;
            }
            return pred;
        }

        if (n->key < key) {
            return _predecessor(n->right, n, key);
        }
        return _predecessor(n->left, pred, key);
    }

    void bshow(node* n, std::string heranca) {
        if (n != nullptr && (n->left != nullptr || n->right != nullptr))
            bshow(n->right, heranca + "r");
        for (int i = 0; i < (int)heranca.size() - 1; i++)
            std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
        if (heranca != "")
            std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
        if (n == nullptr) {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << n->key << std::endl;
        if (n != nullptr && (n->left != nullptr || n->right != nullptr))
            bshow(n->left, heranca + "l");
    }

    int* _to_array(node* n, int* arr) {
        if (n == nullptr) {
            return arr;
        }

        arr = _to_array(n->left, arr);
        *arr = n->key;
        arr++;
        arr = _to_array(n->right, arr);

        return arr;
    }

   public:
    avl_tree() = default;

    avl_tree(const avl_tree& other) {
        _root = _copy(other._root);
        _size = other._size;
    }

    ~avl_tree() { 
        clear(); 
    }

    avl_tree& operator=(const avl_tree& other) {
        if (this == &other) {
            return *this;
        }

        clear();
        _root = _copy(other._root);
        _size = other._size;

        return *this;
    }

    void swap(avl_tree& other) {
        std::swap(_root, other._root);
        std::swap(_size, other._size);
    }


    void insert(int key) { 
        _root = _insert(_root, key); 
    }

    void remove(int key) {
        if (!contains(key)) {
            throw std::runtime_error("Chave nao encontrada");
        }

        _root = _remove(_root, key);
    }

    bool contains(int key) { 
        return _search(_root, key) != nullptr; 
    }

    void clear() {
        delete _root;
        _root = nullptr;
        _size = 0;
    }

    int minimum() {
        if (empty()) {
            throw std::runtime_error("Arvore vazia");
        }

        return _minimum(_root)->key;
    }

    int maximum() {
        if (empty()) {
            throw std::runtime_error("Arvore vazia");
        }

        return _maximum(_root)->key;
    }

    int successor(int x) {
        if (!contains(x)) {
            throw std::runtime_error("Chave nao encontrada");
        }

        node* s = _successor(_root, nullptr, x);

        if (s == nullptr) {
            throw std::runtime_error("Chave sem sucessor");
        }

        return s->key;
    }

    int predecessor(int x) {
        if (!contains(x)) {
            throw std::runtime_error("Chave nao encontrada");
        }

        node* p = _predecessor(_root, nullptr, x);

        if (p == nullptr) {
            throw std::runtime_error("Chave sem predecessor");
        }

        return p->key;
    }

    bool empty() const { 
        return _size == 0; 
    }

    unsigned int size() const { 
        return _size; 
    }

    int* to_array() {
        int* arr = new int[_size];
        int* ptr = arr;
        _to_array(_root, ptr);
        return arr;
    }

    std::string to_string() {
        int* arr = new int[_size];
        int* ptr = arr;
        _to_array(_root, ptr);

        std::string str = "[";
        for (unsigned int i = 0; i < _size; i++) {
            str += std::to_string(arr[i]);
            if (i < _size - 1) {
                str += ", ";
            }
        }
        str += "]";

        delete[] arr;
        return str;
    }

    void print_tree() { 
        bshow(_root, ""); 
    }
};