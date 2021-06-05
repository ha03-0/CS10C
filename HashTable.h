#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <fstream>
//#include <list>
#include <iostream>
#include "Word.h"


using namespace std;

class HashTable {

 private:
    //list<Word*> *hashTable;
  list<Word*> *hashTable;
    int size;

 public:
    HashTable(int);
  int computeEncodeHash(const string&);
  bool contains(const string &);
  void insert(Word *);
  void encodeHelper(string);


// private:
    //int computeHash(const string &);
  //int computeEncodeHash(const string&);
};

#endif
