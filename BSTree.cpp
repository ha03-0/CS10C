//Collaborated with Chloe
#include <iostream>
#include "BSTree.h"

using namespace std;

BSTree::BSTree() {
    root = new Node(0, "");
}
BSTree::~BSTree() {}

void BSTree::copyTree(Node* copyNode, Node* origNode){
    copyNode = new Node(0, "");
    copyNode -> nodeString = origNode -> nodeString;
    copyNode -> count = origNode -> count;

    if(origNode -> left != 0){
        copyTree(copyNode -> left, origNode -> left);
    }
    if(origNode -> right != 0){
        copyTree(copyNode -> right, copyNode -> right);
    }
}

void BSTree::insert(const string& newNode){
    Node* insertNode = new Node(1, newNode);
    if(root -> count == 0){
        root = insertNode;
        return;
    }
    Node* currNode = root;
    do {
        if(currNode -> nodeString == newNode){
            currNode -> count = currNode -> count + 1;
            return;
        }
        if(currNode -> nodeString < newNode){
            if (currNode -> right == 0){
                currNode -> right = insertNode;
                insertNode -> parent = currNode;
                return;
            }
            currNode = currNode -> right;
        }
        else if(currNode -> nodeString > newNode){
            if(currNode -> left == 0){
                currNode -> left = insertNode;
                insertNode -> parent = currNode;
                return;
            }
            currNode = currNode -> left;
        }
    } while(currNode != insertNode);
}

Node* BSTree::search(Node* searchNode) const{
    string searchString = searchNode -> nodeString;
    Node* currNode = root;

    while(true){
        if(currNode -> nodeString == searchString){
            return currNode;
        }
        if(currNode -> nodeString < searchString){
            if (currNode -> right == 0){
                return root;
            }
            currNode = currNode -> right;
        }
        else if(currNode -> nodeString > searchString){
            if(currNode -> left == 0){
                return root;
            }
            currNode = currNode -> left;
        }
    }
    return root;
}

bool BSTree::search(const string& searchString) const{
    if(root -> count == 0){
        return false;
    }
    Node* currNode = root;
    while(true){
        if(currNode -> nodeString == searchString){
            return true;
        }
        if(currNode -> nodeString < searchString){
            if (currNode -> right == 0){
                return false;
            }
            currNode = currNode -> right;
        }
        else if(currNode -> nodeString > searchString){
            if(currNode -> left == 0){
                return false;
            }
            currNode = currNode -> left;
        }
    }
    return root;
}

void BSTree::inOrder(Node* currNode) const{
    if(currNode == 0){
        return;
    }
    if(currNode -> left != 0){
        inOrder(currNode -> left);
    }
    cout << currNode -> nodeString << "(" << currNode -> count << "), ";
    if(currNode -> right != 0){
        inOrder(currNode -> right);
    }
    return;
}

void BSTree::inOrder() const{
    if(root -> count == 0){
        cout << endl;
        return;
    }
    inOrder(root);
    cout << endl;
}

void BSTree::postOrder(Node* currNode) const{
    if(currNode == 0){
        return;
    }
    if(currNode -> left != 0){
        postOrder(currNode -> left);
    }
    if(currNode -> right != 0){
        postOrder(currNode -> right);
    }
    cout << currNode -> nodeString << "(" << currNode -> count << "), ";
}

void BSTree::postOrder() const{
    if(root -> count == 0){
        cout << endl;
        return;
    }
    postOrder(root);
    cout << endl;
}

void BSTree::preOrder(Node* currNode) const{
    if(currNode == 0){
        return;
    }
    cout << currNode -> nodeString << "(" << currNode -> count << "), ";
    if(currNode -> left != 0){
        preOrder(currNode -> left);
    }
    if(currNode -> right != 0){
        preOrder(currNode -> right);
    }
    return;
}

void BSTree::preOrder() const{
    if(root -> count == 0){
        cout << endl;
        return;
    }
    preOrder(root);
    cout << endl;
}

string BSTree::largest() const{
    if(root -> count == 0){
        return "";
    }
    Node* currNode = root;
    while(currNode -> right != 0){
        currNode = currNode -> right;
    }
    return currNode -> nodeString;
}

string BSTree::smallest() const{
    if(root -> count == 0){
        return "";
    }
    Node* currNode = root;
    while(currNode -> left != 0){
        currNode = currNode -> left;
    }
    return currNode -> nodeString;
}

int BSTree::height(const string& heightString) const{
    if(root -> count == 0 || !search(heightString)){
        return -1;
    }
    Node* searchNode = new Node(1, heightString);

    searchNode = search(searchNode);

    if(searchNode -> left == 0 && searchNode -> right == 0){
        return 0;
    }
    int leftH = 0;
    int rightH = 0;
    if(searchNode -> left != 0){
        leftH = height(searchNode -> left -> nodeString);
    }
    if(searchNode -> right != 0){
        rightH = height(searchNode -> right -> nodeString);
    }
    if(rightH >= leftH){
        return 1 + rightH;
    }
    else{
        return 1 + leftH;
    }
}

void BSTree::remove(const string& removeString){
    if(root -> count == 0 || !search(removeString)){
        return;
    }
    Node* removeNode = new Node(1, removeString);
    removeNode = search(removeNode);

    if(removeNode -> count > 1){
        int newCount = removeNode -> count - 1;
        removeNode -> count = newCount;
        return;
    }

    if(removeNode -> left == 0 && removeNode -> right == 0){ //if removing leaf
        if(removeNode == root){
            root = new Node(0, "");
            return;
        }
        if(removeNode == removeNode -> parent -> left){
            removeNode -> parent -> left = 0;
        }
        if(removeNode == removeNode -> parent -> right){
            removeNode -> parent -> right = 0;
        }
        removeNode -> parent = 0;
        delete removeNode;
        return;
    }

    if(removeNode -> left != 0){
        Node* replace = removeNode -> left;
        while(replace -> right != 0){
            replace = replace -> right;
        }
        int newCount = replace -> count;
        string newNodeString = replace -> nodeString;
        replace -> count = 1;

        remove(newNodeString);

        removeNode -> count = newCount;
        removeNode -> nodeString = newNodeString;
        return;
    }

    else{
        Node* replace = removeNode -> right;

        while(replace -> left != 0){
            replace = replace -> left;
        }

        int newCount = replace -> count;
        string newNodeString = replace -> nodeString;
        replace -> count = 1;

        remove(newNodeString);

        removeNode -> count = newCount;
        removeNode -> nodeString = newNodeString;

        return;
      }
}
