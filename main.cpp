// worked with Chloe
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}
int Partition(int numbers[], int i, int k) {
  int midpoint, pivot, temp, l, h;
  bool done = false;
   /* Pick middle value as pivot */
   midpoint = i + (k - i) / 2;
   pivot = numbers[midpoint];

   /* Initialize variables */
   l = i;
   h = k;

   while (!done) {
      /* Increment l while numbers[l] < pivot */
      while (numbers[l] < pivot) {
         ++l;
      }

      /* Decrement h while pivot < numbers[h] */
      while (pivot < numbers[h]) {
         --h;
      }
      /* If there are zero or one items remaining,
            all numbers are partitioned. Return h */
            if (l >= h) {
               done = true;
            }
            else {
               /* Swap numbers[l] and numbers[h],
                   update l and h */
               temp = numbers[l];
               numbers[l] = numbers[h];
               numbers[h] = temp;

               ++l;
               --h;
            }
         }
         return h;
      }


void Quicksort_midpoint(int numbers[], int i, int k) {
   int j;

   /* Base case: If 1 or zero elements,
      partition is already sorted */
   if (i >= k) {
      return;
   }

   /* Partition the array.
      Value j is the location of last
      element in low partition. */
   j = Partition(numbers, i, k);

   /* Recursively sort low and high
       partitions */
   Quicksort_midpoint(numbers, i, j);
   Quicksort_midpoint(numbers, j + 1, k);
}
int Partition_medianOfThree(int numbers[], int i, int k) {
  int median, pivot, temp, l, h;
  bool done = false;
   /* Pick middle value as pivot */
   int a,b,c;
  /* Pick middle value as pivot */
  a = numbers[i];
  b = numbers[(i+k)/2];
  c = numbers[k];
//^ is exclusive or

  if ((a >b) ^ (a >c)){
    median = a;
  }
  else if ((b < a) ^ (b < c)){
    median = b;
  }
  else {
    median = c;
  }




   pivot = numbers[median];

   /* Initialize variables */
   l = i;
   h = k;

   while (!done) {
      /* Increment l while numbers[l] < pivot */
      while (numbers[l] < pivot) {
         ++l;
      }

      /* Decrement h while pivot < numbers[h] */
      while (pivot < numbers[h]) {
         --h;
      }
      /* If there are zero or one items remaining,
            all numbers are partitioned. Return h */
            if (l >= h) {
               done = true;
            }
            else {
               /* Swap numbers[l] and numbers[h],
                   update l and h */
               temp = numbers[l];
               numbers[l] = numbers[h];
               numbers[h] = temp;

               ++l;
               --h;
            }
         }
         return h;




      }


void Quicksort_medianOfThree(int numbers[], int i, int k){
  int j;

  /* Base case: If 1 or zero elements,
     partition is already sorted */
  if (i >= k) {
     return;
  }

  /* Partition the array.
     Value j is the location of last
     element in low partition. */
  j = Partition(numbers, i, k);

  /* Recursively sort low and high
      partitions */
  Quicksort_medianOfThree(numbers, i, j);
  Quicksort_medianOfThree(numbers, j + 1, k);
}

void InsertionSort(int numbers[], int numbersSize) {
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap

   for (i = 1; i < numbersSize; ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && numbers[j] < numbers[j - 1]) {

         // Swap numbers[j] and numbers[j - 1]
         temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         --j;
      }
   }
}
/*
void displayArray(int numbers[], int n){

  int i;

  cout<<endl<<"Array elements are:"<<endl;

  for(i=0;i<n;i++){

    cout <<"    "<< numbers[i] << endl;

  }

}
*/
int main(){

  int arr1[NUMBERS_SIZE],arr2[NUMBERS_SIZE],arr3[NUMBERS_SIZE];

fillArrays(arr1,arr2,arr3);

  clock_t Start = clock();
  Quicksort_midpoint(arr1,0,NUMBERS_SIZE-1);


//call sort function here
clock_t End = clock();
int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds
cout<< "The Quicksort_midpoint algorithm has runtime "<< elapsedTime <<endl;


Start = clock();
cout << "hello word" << endl;
Quicksort_medianOfThree(arr2,0,NUMBERS_SIZE-1);


//call sort function here
End = clock();
elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds
cout<< "The Quicksort_medianOfThree algorithm has runtime "<< elapsedTime <<endl;



Start = clock();
InsertionSort(arr3,NUMBERS_SIZE);

//displayArray(arr3,NUMBERS_SIZE);
//call sort function here
End = clock();
elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds
cout<< "The InsertionSort algorithm has runtime "<< elapsedTime <<endl;

}
