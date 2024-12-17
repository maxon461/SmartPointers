#include "Node.h"

Node::Node(std::string name) {
    init();
    this->name = name;
    variable = true;
}

Node::Node(float val) {
    init();
    value = val;
}

Node::Node(Operations op) {
    init();
    this->op = op;
}

Node::~Node() {
    delete left;
    delete right;
}