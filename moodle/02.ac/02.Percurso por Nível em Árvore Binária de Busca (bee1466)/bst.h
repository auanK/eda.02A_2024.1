#include <iostream>

class node {
   public:
    int key;
    node* left;
    node* right;

    node(int key) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class bst {
   private:
    node* root;

    void clear(node* current) {
        if (current != nullptr) {
            clear(current->left);
            clear(current->right);
            delete current;
        }
    }

    int height(node* current) {
        if (current == nullptr) {
            return 0;
        } else {
            int left_height = height(current->left);
            int right_height = height(current->right);
            return std::max(left_height, right_height) + 1;
        }
    }

   public:
    bst() { 
        this->root = nullptr; 
    }

    ~bst() { 
        clear(this->root); 
    }

    void _add(node*& current, int value) {
        if (current == nullptr) {
            current = new node(value);
        } else if (value < current->key) {
            _add(current->left, value);
        } else if (value > current->key) {
            _add(current->right, value);
        }
    }

    void add(int value) { 
        _add(this->root, value); 
    }

    void level_order() {
        int h = height(this->root);
        for (int i = 1; i <= h; i++) {
            _level_order(this->root, i);
        }
        std::cout << std::endl;
    }

    void _level_order(node* current, int level) {
        if (current == nullptr) {
            return;
        }
        if (level == 1) {
            std::cout << current->key << " ";
        } else if (level > 1) {
            _level_order(current->left, level - 1);
            _level_order(current->right, level - 1);
        }
    }
};
