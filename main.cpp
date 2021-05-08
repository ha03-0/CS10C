//collaborated with Chloe Georgiou
#include "IntList.h"
#include <iostream>
using namespace std;

int main(){
  int num;
  cout << "Enter number from 1-4: ";
  cin >> num;
  cout << endl;

  if (num == 1){
    cout << "constructor ";
    IntList test1;

    cout << "pushfront 5 6 ";
    test1.push_front(5);
    test1.push_front(6);


    cout << "reverse ";
    test1.printReverse();

    cout << " pushfront 10 11 ";
    test1.push_front(10);
    test1.push_front(11);

    test1.pop_front();
    cout << endl;
  }

  if (num == 2){
    cout << "constructor: ";
    IntList test2;

    cout << "pushback 30 31 ";
    test2.push_back(30);
    test2.push_back(31);

    cout << " reverse ";
    test2.printReverse();

    cout << " pushback 40 41 ";
    test2.push_back(40);
    test2.push_back(41);

    cout << " reverse ";
    test2.printReverse();

    cout << " popback ";
    test2.pop_back();
    cout << endl;
  }

  if (num == 3){
    cout << "constructor ";
    IntList test2;
    if(test2.empty()){
      cout << "empty list " << endl;
    }
    cout << "pushback 15 16 17 ";
    test2.push_back(15);
    test2.push_back(16);
    test2.push_back(17);
    cout << test2 << endl;

    cout << "reverse ";
    test2.printReverse();

    cout << " popback ";
    test2.pop_back();
    cout << test2 << endl;
    cout << endl;
  }

  if (num == 4){
    //<< operator test
    IntList test2;
    cout << "friend operator ";
    cout << test2 << endl;
    test2.push_front(10);
    test2.push_front(11);
    test2.push_front(12);
    test2.pop_back();
    test2.pop_back();
    cout << test2 << endl;
  }
  return 0;
}
