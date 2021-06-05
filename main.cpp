#include <iostream>
#include "HashTable.h"
#include <fstream>
#include <list>
#include <iterator>
using namespace std;

int main(){
  cout << "data compression" << endl;
  /*
  string line;
	int s;
	string message = " ";

	// open input file
	ifstream myfile("tfc.txt");
	if (myfile.fail()) {
	    cout << "could not open file" << endl;
	    exit(1);
	}

	//create hash table
	//HashTable table(20071);



  string line;
  ofstream outFS("output.txt");
  if(!outFS.is_open()){
      cout<<"Error"<<endl;
      return;
  }
  while (!myfile.eof()) {
      getline(myfile, line);
    int len = line.size();
    while(len > 0) {
        string sub;
        len = line.find(" ");
        if (len > 0) {
            sub = line.substr(0, len);
            line = line.substr(len + 1, line.size());
        }
        else {
            sub = line.substr(0, line.size() - 1);
        }
          int hashIndex = computeEncodeHash(sub);
          int code = 0;
          list<Word*>::iterator it;
          for (it = hashTable[hashIndex].begin(); it != hashTable[hashIndex].end(); it++){
              if (sub == (*it)->token) {
                  code = (*it)->code;
              }
          }
          outFS << code << " ";
      }
      outFS << endl;
  }
  outFS.close();
}
*/
	return 0;
}
