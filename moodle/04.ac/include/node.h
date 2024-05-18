#pragma once

struct node {
    int key;
    unsigned int height;
    node* left;
    node* right;

    node(int key, unsigned int height, node* left, node* right) {
        this->key = key;
        this->height = height;
        this->left = left;
        this->right = right;
    }
};