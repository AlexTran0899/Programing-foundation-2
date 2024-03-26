//
// Created by Alex Tran on 4/29/23.
//

#include "Tree.h"

Tree::Tree() {
    this->root = nullptr;
    this->count = 0;
}
Tree::Tree(Book book){
    this->root = new Node(book, nullptr, nullptr);
    this->count = 0;
}

Tree::Tree(const Tree * copy) {
    this->root = nullptr;
}
Tree::~Tree() {
    this->root = nullptr;
}

Node * Tree::getRoot() const {
    return root;
}

int Tree::getCount() const {
    return count;
}

Book Tree::getBookByTitle(string title) const {
    Node * curr = this->root;
    return getBookByTitleHelper(title, curr);
}

Book Tree::getBookByTitleHelper(string title, Node *& curr) const {
    if(curr == nullptr) {
        return Book();
    }
    if(curr->getVal().getTitle() == title) {
        return curr->getVal();
    }
    if(curr->getVal().getTitle() > title){
        return getBookByTitleHelper(title, curr->getLeft());
    } else {
        return getBookByTitleHelper(title, curr->getRight());
    }
}

void Tree::setRoot(Node * root) {
    Tree::root = root;
}

void Tree::insertBook(Book book) {
    Node * curr = this->root;
    if(this->root == nullptr){
        this->root = new Node(book, nullptr, nullptr);
        return;
    }
    return insertBookHelper(book, curr);
}

void Tree::insertBookHelper(Book book, Node *& curr){
    if(curr == nullptr) {
        curr = new Node(book, nullptr, nullptr);
        return;
    }
    string currTitle = curr->getVal().getTitle();
    string bookTitle = book.getTitle();

    if(currTitle > bookTitle){
        return insertBookHelper(book, curr->getLeft());
    } else {
        return insertBookHelper(book, curr->getRight());
    }
}

void Tree::deleteBook(string title) {
    if(this->root == nullptr) return;
    Node * curr = this->root;
    deleteBookHelper(title, curr);
}

Node * Tree::deleteBookHelper(string bookTitle, Node *& root) {
    string currBookTitle = root->getVal().getTitle();
    if(currBookTitle > bookTitle) root->setLeft(deleteBookHelper(bookTitle, root->getLeft()));
    else if(currBookTitle < bookTitle) root->setRight(deleteBookHelper(bookTitle, root->getRight()));
    else {
        // case 1: no children
        if(root->getLeft() == nullptr && root->getRight() == nullptr) {
            delete root;
            root = nullptr;
        }
        // case 2: one child
        else if(root->getLeft() == nullptr) {
            Node * temp = root;
            root = root->getRight();
            delete temp;
            temp = nullptr;
        }
        else if(root->getRight() == nullptr) {
            Node * temp = root;
            root = root->getLeft();
            delete temp;
            temp = nullptr;
        }
        // case 3: 2 children
        else {
            Node * temp = findMin(root->getRight());
            root->setVal(temp->getVal());
            root->setRight(deleteBookHelper(temp->getVal().getTitle(), root->getRight()));
        }
    }
    return root;
}

Node * Tree::findMin(Node * curr) const {
    while(curr->getLeft() != nullptr) {
        curr = curr->getLeft();
    }
    return curr;
}

void Tree::rebalancesTree() {
    if(this->root == nullptr) {
        return;
    }

    vector<Book> arr;
    Node * temp = this->root;

    // vector sorted by title (in order traversal)
    dataDump(arr, temp);
    delete this->root;
    this->root = rebalancesTreeHelper(arr, 0, arr.size());
}

Node * Tree::rebalancesTreeHelper(vector<Book> arr, int start, int end) {
    if(start >= end) return nullptr;
    int mid = (start+end)/2;
    Node * root = new Node(arr[mid], nullptr, nullptr);
    root->setLeft(rebalancesTreeHelper(arr ,start, mid));
    root->setRight(rebalancesTreeHelper(arr ,mid+1, end));
    return root;
}

void Tree::dataDump(vector<Book> & arr, Node *& curr) {
    if (curr != nullptr)
    {
        dataDump(arr,curr->getLeft());
        arr.push_back(curr->getVal());
        dataDump(arr,curr->getRight());
    }
}

void Tree::print() const {
    Node * curr = this->root;
    printHelper(curr);
}

void Tree::printHelper(Node *& curr) const
{
    if (curr != nullptr)
    {
        printHelper(curr->getLeft());
        curr->getVal().print();
        printHelper(curr->getRight());

    }
}