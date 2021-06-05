#ifndef __NODE_H__
#define __NODE_H__

using namespace std;

class Node{
    friend class BSTree;

    private:
        int count;
        string nodeString;
        Node* left;
        Node* right;
        Node* parent;

    public:
        Node(int count, string nodeString) : count(count),
        nodeString(nodeString), left(0), right(0), parent(0) {}
};

#endif
