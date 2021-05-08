//Collaborated with Chloe Georgiou
#include <iostream>
#include "WordLadder.h"
#include <string>
#include <vector>
#include <ostream>
#include <fstream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

WordLadder::WordLadder(const string &inFile){
    ifstream inFS;
    inFS.open(inFile.c_str());

    if(!inFS.is_open()) {
        cout << "Error" << endl;
        return;
    }

    else {
        string word;

        while(!inFS.eof()) {
            inFS >> word;
            if(word.length() != 5) {
              cout << "Error" << endl;
              return;
            }

          dict.push_back(word);
        }
        inFS.close();
    }
    return;
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile){

  ofstream outFS;
    outFS.open(outputFile.c_str());
    if (!outFS.is_open()) {
        cout << "Opening output file failed." << endl;
        return;
    }



    bool found;
    found = find(dict.begin(), dict.end(), start) != dict.end();

    if (!found) {
        cout << "Start word not found" << endl;
        return;
    }
    found = find(dict.begin(), dict.end(), end) != dict.end();
    if (!found) {
        cout << "End word not found" << endl;
        return;
    }

    if (start == end) {
        outFS<< start;
        outFS.close();
        return;
    }
    queue<stack<string>> initQueue;
    stack<string> initStack;

    initStack.push(start);
    initQueue.push(initStack);
    string word;
    list<string>::iterator it;
    dict.remove(start);
    while(!initQueue.empty()){
      //get the word on top of the front Stack of this Queue
      //for each word in the dictionary
      word = initQueue.front().top();
        for (it = dict.begin(); it != dict.end(); ++it) {

            if (OffByOne(word, *it)) {
                stack<string> stackCopy = initQueue.front();
                stackCopy.push(*it);

                if(*it == end){
                    printLadder(stackCopy, outFS);
                    return;
                }
                initQueue.push(stackCopy);
                it = dict.erase(it);

                --it;
            }
        }
        initQueue.pop();
    }

  //  if (outFS.is_open()) {
        outFS << "No Word Ladder Found.";
    //  }

}
bool WordLadder::OffByOne(string word, string inDict){
  int match = 0;
    for (int i = 0; i < 5; ++i) {
        if (word[i] == inDict[i]) {
            ++match;
            }
        }
    if (match == 4) {
        return true;
    }
    else {
        return false;
    }
}
void WordLadder::printLadder(stack<string> revLadder, ofstream &outFS) {
  stack <string> ladder;
  int items = 0;
    while(!revLadder.empty()){
      ladder.push(revLadder.top());
      ++items;
      revLadder.pop();
    }

    while (!ladder.empty()){
      outFS << ladder.top();
      ladder.pop();
      --items;
      if (items != 0){
      outFS << " ";
    }
  }
    return;
  }
