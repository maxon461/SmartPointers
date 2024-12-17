//
// Created by Maksym Selishchev on 17/12/2024.
//

#ifndef MATHTREEV4_MATHTREE_H
#define MATHTREEV4_MATHTREE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>


#include "CResult.h"
#include "CError.h"
#include "Operations.h"
#include "Node.h"

class MathTree
{
private:

    Node *root;
    std::vector<Node *> vars;

    void printVars();
    float compile(Node *root, std::vector<float> *values);
    void join(std::string formula);
    void clear();
    void print(Node *root);
    void create(std::string formula);
    bool empty() const;

    Node* copyTree(Node* source);
    void copyVars(const std::vector<Node*>& otherVars);

    std::vector<std::string> splitString(std::string formula);
    Node *createHelper(std::vector<std::string> *elements);
    bool isStringANumber(std::string string);
    Node *findNodeInVectorByName(std::vector<Node *> *vector, std::string string);


public:
    MathTree() : root(nullptr) {}
    CResult<MathTree*, CError> createTree(std::string formula);
    void saveToFile(const CResult<MathTree*, CError>& result, const std::string& filename);
    void menu();
    void printTree() {
        print(root);
    }

    bool isEmpty() const {
        return empty();
    }

    static int getCopyCount();
    static int getMoveCount();
    static void resetCounters();

    MathTree(const MathTree& other);
    MathTree(MathTree&& other);
    MathTree operator=(const MathTree& other);
    MathTree& operator=(MathTree&& other);
    MathTree operator+(const MathTree& other);
};

void mt_test();


#endif //MATHTREEV4_MATHTREE_H
