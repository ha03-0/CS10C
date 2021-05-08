//Collaborated with Chloe Georgiou
#include <iostream>
#include "Heap.h"
#include <algorithm>
using namespace std;

Heap::Heap() {
    numItems = 0;
}

void Heap::enqueue ( PrintJob* obj){
  if(numItems < MAX_HEAP_SIZE) {
        arr[numItems] = obj;
        bubbleUp(numItems);
        ++numItems;
    }
}

void Heap::dequeue ( ){
  if(numItems == 1) {
        numItems = 0;
    arr[0] = nullptr;
        return;
    }
    if(numItems > 1) {
        arr[0] = arr[numItems-1];
        arr[numItems-1] = nullptr;
        --numItems;
        trickleDown(0);
    }
}

PrintJob* Heap::highest ( ){
  if(numItems == 0) {
        return nullptr;
    }
    return arr[0];
}

void Heap::print ( ){
  if(numItems == 0) {
        return;
    }
    else {
        cout << "Priority: " << highest()->getPriority() << ", ";
        cout << "Job Number: " << highest()->getJobNumber() << ", ";
        cout << "Number of Pages: " << highest()->getPages() << endl;
    }
    return;
}
void Heap::trickleDown(int nodeIndex){
  int childIndex = 2 * nodeIndex + 1;
  int value = arr[nodeIndex]->getPriority();
  int maxValue;
  int maxIndex;
  while (childIndex < numItems){
    maxValue = value;
    maxIndex = -1;
    for (int i = 0; i < 2 && i + childIndex < numItems; ++i) {
       if (arr[i + childIndex]->getPriority() > maxValue) {
          maxValue = arr[i + childIndex]->getPriority();
          maxIndex = i + childIndex;
       }
    }
    if (maxValue == value) {
       return;
    }
    else {
       swap(arr[nodeIndex] , arr[maxIndex]);
       nodeIndex = maxIndex;
       childIndex = 2 * nodeIndex + 1;
    }
  }
}

void Heap::bubbleUp(int up) {
  int parentIndex;
  while (up > 0){
    parentIndex = (up-1)/2;
    if (arr[up]->getPriority() <= arr[parentIndex]->getPriority()){
      return;
    }
    else {
      swap(arr[up], arr[parentIndex]);
        up = parentIndex;
    }
  }

}
