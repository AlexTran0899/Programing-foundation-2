//
// Created by Alex Tran on 4/29/23.
//

#ifndef HW7_NODE_H
#define HW7_NODE_H
#include "Book.h"

class Node {
public:
    Node();
    Node(Book val, Node * left, Node *  right);
    Node(const Node & copy);
    ~Node();
    Book getVal();

    void setVal(Book val);

    Node *& getLeft();

    void setLeft(Node *left);

    Node *& getRight();

    void setRight(Node *right);

private:
    Book val;
    Node * left;
    Node * right;
};


#endif //HW7_NODE_H
