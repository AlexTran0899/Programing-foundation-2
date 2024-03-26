//
// Created by Alex Tran on 4/29/23.
//

#include "Node.h"

Node::Node(){
    this->val = Book();
    this->left = nullptr;
    this->right = nullptr;
}
Node::Node(Book val, Node * left, Node *  right){
    this->val = val;
    this->left = left;
    this->right = right;
}
Node::Node(const Node & copy){
    this->val = copy.val;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node(){
    delete this->left;
    delete this->right;
    this->left = nullptr;
    this->right = nullptr;
}

Book Node::getVal()  {
    return val;
}

void Node::setVal(Book val) {
    this->val = val;
}

Node *& Node::getLeft()  {
    return left;
}

void Node::setLeft(Node *left) {
    Node::left = left;
}

Node *& Node::getRight() {
    return right;
}

void Node::setRight(Node *right) {
    Node::right = right;
}
