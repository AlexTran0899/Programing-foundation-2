//
// Created by Alex Tran on 4/29/23.
//

#ifndef HW7_TREE_H
#define HW7_TREE_H
#include "Node.h"
class Tree {
public:
    Tree();
    Tree(Book book);
    Tree(const Tree * copy);
    ~Tree();

    // setter
    void setRoot(Node *root);
    void setCount(int count);

    // getter
    Node *getRoot() const;
    int getCount() const;
    Book getBookByTitle(string title) const ;

    // util
    void insertBook(Book book);
    void deleteBook(string title);
    void rebalancesTree();
    void print() const;

private:
    Node * root;
    int count;
    void insertBookHelper(Book book, Node *& curr);
    void printHelper(Node *& curr) const;
    Book getBookByTitleHelper(string title, Node *& curr) const;
    Node * deleteBookHelper(string bookTitle, Node *& curr);
    Node * findMin(Node * curr) const;
    Node * rebalancesTreeHelper(vector<Book> arr, int start, int end);
    void dataDump(vector<Book> & arr, Node *& curr);
};


#endif //HW7_TREE_H
