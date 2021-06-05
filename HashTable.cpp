//Collaborated with Laiba Hasan in homework 4
#include <iostream>
#include "HashTable.h"
#include <fstream>
#include <list>
#include <iterator>
using namespace std;

HashTable::HashTable(int a) {
    size = a;
    hashTable = new list<Word*>[size];
}

int HashTable::computeEncodeHash(const string& word) {
    unsigned long stringHash = 5837;
    for (unsigned i = 0; i < word.length(); i++) {
        stringHash = (stringHash * 33) + word[i];
    }
    return stringHash % size;
}


bool HashTable::contains(const string& word) {
    int hIn = computeEncodeHash(word);
    list<Word*>::iterator it;
    for (it = hashTable[hIn].begin(); it != hashTable[hIn].end(); it++){
        if ((*it)->token == word) {
            return true;
        }
    }
    return false;
}

void HashTable::insert( Word* word){
    int hIn = computeEncodeHash(word->token);
    hashTable[hIn].push_back(word);
}

void HashTable::encodeHelper(string nameOfFile) {
    ifstream myfile(nameOfFile);
	if (myfile.fail()) {
	    cout << "could not open the  file" << endl;
	    return;
	}
    string line;
    ofstream outFS("output.txt");
    if(!outFS.is_open()){
        cout<<" ERRROR "<<endl;
        return;
    }
    while (!myfile.eof()) {
        getline(myfile, line);
	    int length = line.size();
	    while(length > 0) {
	        string sub;
	        length = line.find(" ");
	        if (length > 0) {
	            sub = line.substr(0, length);
	            line = line.substr(length + 1, line.size());
	        }
	        else {
	            sub = line.substr(0, line.size() - 1);
	        }
            int hIn = computeEncodeHash(sub);
            int code = 0;
            list<Word*>::iterator it;
            for (it = hashTable[hIn].begin(); it != hashTable[hIn].end(); it++){
                if (sub == (*it)->token) {
                    code = (*it)->code;
                }
            }
            outFS << code << "    ";
        }
        outFS << endl;
    }
    outFS.close();
}
