//collaborated iwth Chloe
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include "arithmeticExpression.h"
using namespace std;

arithmeticExpression::arithmeticExpression(const string &input){
  root = 0;
  infixExpression = input;
}

void arithmeticExpression::buildTree(){
  infixExpression = infix_to_postfix();
	stack <TreeNode*> stk;

	for (unsigned int i = 0; i < infixExpression.size(); ++i) {
		TreeNode *item = new TreeNode(infixExpression.at(i), 'a' + i);

		if (priority(infixExpression.at(i)) == 0) {
			stk.push(item);
		}

		else if (priority(infixExpression.at(i)) > 0) {
      root = item;
			item->right = stk.top();
			stk.pop();
			item->left = stk.top();
			stk.pop();
			stk.push(item);
		}
	}
}

void arithmeticExpression::infix(){
  infix(root);
  return;
}

void arithmeticExpression::prefix(){
  prefix(root);
  return;
}

void arithmeticExpression::postfix(){
  postfix(root);
  return;
}

void arithmeticExpression::infix(TreeNode *node){
  if (node == 0) {
		return;
	}
	if (priority(node->data) > 0) {
		cout << "(";
		infix(node->left);
		cout << node->data;
		infix(node->right);
		cout << ")";
	}
	else {
		infix(node->left);
		cout << node->data;
		infix(node->right);
	}
}

void arithmeticExpression::prefix(TreeNode *node){
  if (node == 0) {
		return;
	}
	cout << node->data;
	prefix(node->left);
	prefix(node->right);
}

void arithmeticExpression::postfix(TreeNode *node){
  if (node == 0) {
		return;
	}

	postfix(node->left);
	postfix(node->right);
	cout << node->data;
}

void arithmeticExpression::visualizeTree(ofstream & outFS, TreeNode *n){
    if(n){
        outFS<<n->key << "[ label = \""<<n->data<<"\"];"<<endl;
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->key <<" -> " <<n->left->key<<";"<<endl;
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->key <<" -> " <<n->right->key<<";"<<endl;
        }
    }
}


int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
