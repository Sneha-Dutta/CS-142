//quicksort
//1. choose the pivot
//2.partition
//3.recursion function
//4. stop when partition has only 1 element

//first include library
#include<iostream>
using namespace std;

//interchanging elements of an array
void interchange(int arr[], int i1, int i2) {
   //i1 and i2 are two specific element index positions
   int x= arr[i2];
   arr[i2] = arr[i1];
   arr[i1] = x;
}

//to display elements of an array
void display(int arr[], int size) {
   for (int i=0; i< size; i++) {
      cout << arr[i] << ", ";
   }
   cout << endl;
}

//function for partion
int part(int arr[], int low, int high) {
   //put the elements smaller than pivot on its left side, and the elements larger than pivot on its right side
   int pvt= high;
   //i shows the position of low
   int i= low-1;
   int j = low;

   while (j<= high-1) {
      if (arr[j] <=arr[pvt]) {
         i=i+1;
         interchange(arr, i, j);
      }
      j=j+1;
   }
   //i divides the array to two parts, left with smaller than the pivot , right has elements larger than pivot
   interchange(arr, i+1, pvt);
   return i+1;
}
//recursive function to quick sort 
void quicksort( int arr[], int low, int high) {
   if ( low< high) {
      int p= part(arr, low, high);
      quicksort(arr, low, (p-1));
      quicksort(arr, (p+1), high);
   }
}
//write the main function
int main() {
   int arr[10]= {5, 4, 8, 10, 12, 6, 9, 24, 19, 7};
   display(arr, 10);
   quicksort(arr, 0, 9);
   display(arr, 10);
   return 0;
}
