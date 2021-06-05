#ifndef AVLTREE_H
#define AVLTREE_H
#include "Node.h"

using namespace std;

class AVLTree {
    public:
        AVLTree();
        void insert(const string &);
        int balanceFactor(Node*);
        void printBalanceFactors();
        void visualizeTree(const string &);

    private:
        Node* root;
        Node* findUnbalancedNode(Node*);
        Node* insertBalanced(const string &);
        void rotateLeft(Node*);
        void rotateRight(Node*);
        void rightleft(Node*);
        void leftright(Node*);
        int height(Node*) const;
        void printBalanceFactors(Node *);
        void visualizeTree(ofstream &, Node *);
};
#endif
