#pragma once

#include "avl_tree.h"

class set {
   private:
    avl_tree tree = avl_tree();

   public:
    set() = default;

    ~set() {
        tree.~avl_tree();
    }

    void insert(int key) { 
        tree.insert(key); 
    }

    void erase(int key) { 
        tree.remove(key); 
    }

    bool contains(int key) { 
        return tree.contains(key); 
    }

    unsigned int size() const { 
        return tree.size(); 
    }

    bool empty() { 
        return tree.empty(); 
    }

    void clear() { 
        tree.clear(); 
    }

    void swap(set& other) { 
        tree.swap(other.tree);
    }


    int minimum() { 
        return tree.minimum(); 
    }

    int maximum() { 
        return tree.maximum(); 
    }

    int successor(int key) { 
        return tree.successor(key); 
    }

    int predecessor(int key) { 
        return tree.predecessor(key); 
    }

    set union_set(set& other) {
        int* keys = tree.to_array();
        int* other_keys = other.tree.to_array();
        set new_set;
        for (unsigned int i = 0; i < tree.size(); i++) {
            new_set.insert(keys[i]);
        }
        for (unsigned int i = 0; i < other.tree.size(); i++) {
            new_set.insert(other_keys[i]);
        }

        delete[] keys;
        delete[] other_keys;
        return new_set;
    }

    set intersection_set(set& other) {
        int* keys = tree.to_array();
        set new_set;
        for (unsigned int i = 0; i < tree.size(); i++) {
            if (other.contains(keys[i])) {
                new_set.insert(keys[i]);
            }
        }

        delete[] keys;
        return new_set;
    }

    set difference_set(set& other) {
        int* keys = tree.to_array();
        set new_set;
        for (unsigned int i = 0; i < tree.size(); i++) {
            if (!other.contains(keys[i])) {
                new_set.insert(keys[i]);
            }
        }

        delete[] keys;
        return new_set;
    }

    std::string to_string() { 
        return tree.to_string(); 
    }

    void print_tree() { 
        tree.print_tree(); 
    }
};
