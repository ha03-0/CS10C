//collaborated with Chloe Georgiou
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

template<class T>
unsigned min_index(const vector<T> &vals, unsigned index){
  int position;
  T smallestElement;
  unsigned j;
  smallestElement = vals.at(index);
  position = index;
  for (j=index+1; j < vals.size(); ++j){
    if (vals.at(j) < smallestElement){
      smallestElement = vals.at(j);
      position = j;
    }
  }

  return position;
}
template<class T>
void selection_sort(vector<T> &vals){
  int position;
  T temp;
  for (long unsigned int i = 0; i<vals.size(); ++i){
    position = min_index(vals, i);
    temp = vals.at(i);
    vals.at(i) = vals.at(position);
    vals.at(position) = temp;
  }
  return;
}
vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<class T>
T getElement(vector<T> vals, int index){
  return vals.at(index);
}


int main(){
  //Part one
  vector <int> vInt;
  vInt.push_back(10);
  vInt.push_back(11);
  vInt.push_back(12);

  vInt.push_back(5);
  vInt.push_back(6);
  vInt.push_back(7);
  selection_sort(vInt);
  for (long unsigned int i = 0; i< vInt.size(); ++i){
    cout << vInt.at(i) << " ";
  }


    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         try{
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
       }
       catch (const out_of_range& excpt) {
         cout << "out of range exception occured" << endl;
       }
    }


    return 0;
}
