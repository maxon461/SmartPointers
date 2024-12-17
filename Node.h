#ifndef NODE_H
#define NODE_H

#include <string>
#include "Operations.h"

class MathTree;

class Node {
    friend class MathTree;

public:
    explicit Node(std::string name);
    explicit Node(float val);
    explicit Node(Operations op);
    ~Node();

private:
    Node* left;
    Node* right;
    float value;
    std::string name;
    bool variable;
    Operations op;

    void init() {
        left = nullptr;
        right = nullptr;
        value = 0;
        variable = false;
        op = NIL;
    }
};

#endif