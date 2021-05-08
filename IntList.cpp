//collaborated with Chloe Georgiou
#include <iostream>
#include <string>
using namespace std;

#include "IntList.h"

IntList::IntList(){
  dummyHead = new IntNode(0);
  dummyTail = new IntNode(0);
  dummyHead->next = dummyTail;
  dummyTail->prev = dummyHead;
}

IntList::~IntList(){
  while(dummyHead -> next != dummyTail){
    pop_front();
  }
  delete dummyHead;
  delete dummyTail;
}

void IntList::push_front(int value){
  IntNode* temp;
  temp = new IntNode(value);

  if(empty()){
    dummyHead->next = temp;
    dummyTail->prev = temp;
    temp->prev = dummyHead;
    temp->next = dummyTail;
  }
  else{
    temp->next = dummyHead->next;
    dummyHead->next->prev = temp;
    temp->prev = dummyHead;
    dummyHead -> next = temp;
  }
}

void IntList::pop_front(){
  if(dummyHead -> next != dummyTail){
    IntNode* oldHeadNode = dummyHead -> next;

if(dummyHead -> next == dummyTail -> prev){
  dummyTail -> prev = dummyHead;
  dummyHead -> next = dummyTail;
}
  else{
    dummyHead -> next = oldHeadNode -> next;
    oldHeadNode -> next -> prev = dummyHead;
  }

}
}
void IntList::push_back(int value){
  IntNode* temp;
  temp = new IntNode(value);

  if (empty()){
    temp -> prev = dummyTail -> prev;
    dummyTail -> prev -> next = temp;
    temp -> next = dummyTail;
    dummyTail -> prev = temp;
  }
  else{
    temp -> prev = dummyTail -> prev;
    dummyTail -> prev -> next = temp;
    temp -> next = dummyTail;
    dummyTail -> prev = temp;
  }
}

void IntList::pop_back(){
  if(dummyTail -> prev != dummyHead){
    IntNode* oldTailNode = dummyTail ->prev;

    if (dummyHead -> next == dummyTail -> prev){
      dummyTail -> prev = dummyHead;
      dummyHead -> next = dummyTail;
    }
    else{
      dummyTail -> prev = oldTailNode-> prev;
      oldTailNode -> prev -> next = dummyTail;
    }
  }
}

bool IntList::empty() const{
  if (dummyHead->next != dummyTail){
    return false;
  }
  else{
  return true;
  }
}

ostream& operator << (ostream &out, const IntList &rhs){
  if (rhs.empty()){
    return out;
  }
  IntNode* curObj = rhs.dummyHead -> next;
  while(curObj != rhs.dummyTail){
    out << curObj -> data;
    curObj = curObj -> next;
    if(curObj != rhs.dummyTail){
      out<< " ";
    }
  }
  return out;
}


void IntList::printReverse() const{
  IntNode* curObj = dummyTail -> prev;

  while (curObj != dummyHead){
    cout << curObj -> data;
    curObj = curObj -> prev;
    if (curObj != dummyHead){
      cout << " ";
    }
  }
}
