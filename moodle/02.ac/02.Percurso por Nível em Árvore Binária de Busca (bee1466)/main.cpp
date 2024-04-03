#include <iostream>
#include "bst.h"

int main() {
    int c, n, x;
    std::cin >> c;

    for (int i = 1; i <= c; i++) {
        std::cout << "Case " << i << ":" << std::endl;
        std::cin >> n;
        bst tree;
        for (int j = 0; j < n; j++) {
            std::cin >> x;
            tree.add(x);
        }
        tree.level_order();
        std::cout << std::endl;
    }
    
    return 0;
}