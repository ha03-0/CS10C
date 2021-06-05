#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
using namespace std;

class Node{
    friend class AVLTree;

    private:
        int balanceFactor;
        string data;
        Node* left;
        Node* right;
        Node* parent;

    public:
        Node(int balanceFactor, string data) : balanceFactor(balanceFactor), data(data),
        left(0), right(0), parent(0) {}
};
#endif
