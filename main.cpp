// main.cpp
#include <iostream>
#include "CSmartPointer.h"
#include "MathTree.h"



int main() {
    MathTree tree1;
    MathTree tree2;

    tree1.createTree("+ 3 4");
    tree2.createTree("* 2 5");

    std::cout << "Initial trees:\n";
    std::cout << "Tree1: ";
    tree1.printTree();
    std::cout << "\nTree2: ";
    tree2.printTree();
    std::cout << "\n\n";

    std::cout << "Testing addition operator:\n";
    MathTree tree3 = tree1 + tree2;
    std::cout << "Tree3 (tree1 + tree2): ";
    tree3.printTree();
    std::cout << "\n\n";

    std::cout << "Testing move assignment:\n";
    MathTree tree4;
    tree4 = std::move(tree3);
    std::cout << "Tree4 (after move from tree3): ";
    tree4.printTree();
    std::cout << "\nTree3 (after move): ";
    if (tree3.isEmpty()) {
        std::cout << "empty";
    } else {
        tree3.printTree();
    }
    std::cout << "\n\n";

    std::cout << "Testing copy assignment:\n";
    MathTree tree5;
    tree5 = tree4;
    std::cout << "Tree5 (copy of tree4): ";
    tree5.printTree();
    std::cout << "\nTree4 (original): ";
    tree4.printTree();
    std::cout << "\n";

    return 0;
}