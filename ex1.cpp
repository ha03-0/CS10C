// https://learn.zybooks.com/zybook/UCRCS010CWinter2021/chapter/7/section/2
#include "AVLTree.h"
#include <iostream>
#include <fstream>

AVLTree::AVLTree() {
    root = nullptr;
}

void AVLTree::insert(const string& newString) {
    Node* newNode = new Node(newString);
    // if tree empty
    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node* currNode = root;
    while (currNode != nullptr) {
        // either places newNode on the left or moves down left side
        if (newNode->data < currNode->data) {
            if (currNode->left == nullptr) {
                currNode->left = newNode;
                newNode->parent = currNode;
                currNode = nullptr;
            }
            else {
                currNode = currNode->left;
            }
        }
        // either places newNode on the right or moves down right side
        else if (newNode->data > currNode->data) {
            if (currNode->right == nullptr) {
                currNode->right = newNode;
                newNode->parent = currNode;
                currNode = nullptr;
            }
            else {
                currNode = currNode->right;
            }
        }
        else {
            return;
        }
    }
    // moves up the tree from the inserted node, and rebalances along the way
    newNode = newNode->parent;
    while (newNode != nullptr) {
        visualizeTree("output.txt");
        AVLTreeRebalance(newNode);
        visualizeTree("output.txt");
        newNode = newNode->parent;
    }
}

void AVLTree::AVLTreeRebalance(Node* node) {
    AVLTreeUpdateHeight(node);
    if(AVLTreeGetBalance(node) == -2){
        if(AVLTreeGetBalance(node->right) == 1){
            //double rotation, right-left
            rotateRight(node->right);
        }
        rotateLeft(node);
    }
    else if(AVLTreeGetBalance(node) == 2){
        if(AVLTreeGetBalance(node->left) == -1){
            //double rotation, left-right
            rotateLeft(node->left);
        }
        rotateRight(node);
    }
}

void AVLTree::AVLTreeUpdateHeight(Node* node) {
    int leftHeight = -1;
    int rightHeight = -1;
    if (node->left != nullptr) {
        leftHeight = node->left->height;
    }
    if (node->right != nullptr) {
        rightHeight = node->right->height;
    }
    node->height = max(leftHeight, rightHeight) + 1;
}

int AVLTree::AVLTreeGetBalance(Node* node){
    int leftHeight = -1;
    int rightHeight = -1;

    if(node->left != nullptr){
        leftHeight = node->left->height;
    }
    if (node->right != nullptr) {
        rightHeight = node->right->height;
    }
    return leftHeight - rightHeight;

}

void AVLTree::rotateLeft(Node* node) {
    Node* rightLeftChild = node->right->left;
    if (node->parent != nullptr) {
        // node's parent points to node's right child
        AVLTreeReplaceChild(node->parent, node, node->right);
    }
    // node is the root
    else {
        root = node->right;
        root->parent = nullptr;
    }
    // node becomes node->right's left child
    AVLTreeSetChild(node->right, "left", node);
    // rightLeftChild becomes node's right child;
    AVLTreeSetChild(node, "right", rightLeftChild);
}

void AVLTree::rotateRight(Node* node) {
    Node* leftRightChild = node->left->right;
    if (node->parent != nullptr) {
        // node's parent points to node's left child
        AVLTreeReplaceChild(node->parent, node, node->left);
    }
    // node is the root
    else {
        root = node->left;
        root->parent = nullptr;
    }
    // node becomes node-left's right child
    AVLTreeSetChild(node->left, "right", node);
    // leftRightChild becomes node's left child
    AVLTreeSetChild(node, "left", leftRightChild);
}

bool AVLTree::AVLTreeReplaceChild(Node* parent, Node* currentChild, Node* newChild) {
    if (parent->left == currentChild) {
        return AVLTreeSetChild(parent, "left", newChild);
    }
    else if (parent->right == currentChild) {
        return AVLTreeSetChild(parent, "right", newChild);
    }
    return false;
}

bool AVLTree::AVLTreeSetChild(Node* parent, string whichChild, Node* child) {
    if (whichChild != "left" && whichChild != "right") {
        return false;
    }
    if (whichChild == "left") {
        parent->left = child;
    }
    else {
        parent->right = child;
    }
    if (child != nullptr) {
        child->parent = parent;
    }
    AVLTreeUpdateHeight(parent);
    return true;
}


void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
    cout << endl;
}

void AVLTree::printBalanceFactors(Node* node) {
    if (node == nullptr) {
        return;
    }
    printBalanceFactors(node->left);
    cout << node->data << "(" << AVLTreeGetBalance(node) << ")" << ", ";
    printBalanceFactors(node->right);
}

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS, root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;
        }
    }
}
