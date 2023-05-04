#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int maximum = root;  //Initializing the root as the index of largest value
   int left = 2*root + 1;  //Index of the left child node
   int right = 2*root + 2;  //Index of the right child node

   //If left node is larger than the root
   if (left<n && arr[left]>arr[maximum]){
      maximum = left;
   }

   //If right node is larger than the largest
   if (right<n && arr[right]>arr[maximum]){
      maximum = right;
   }

   //If largest is not the root
   if (maximum != root) {
      //set maximum value to the root node
      swap(arr[root], arr[maximum]);

      //Recursively heapify
      heapify(arr, n, maximum);
    } 
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i=n/2-1; i>=0; i--){
      heapify(arr, n, i);
   }   
  
   // extracting elements from heap one by one
    for (int i=n-1; i>=0; i--) {
      //Move current root to the end to sort
      swap(arr[0], arr[i]);

        //call max heapify without the last max element
      heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
   

}
  
// main program
int main()
{
   /* assign random values to the array

   srand(time(NULL));    // seed the random number generator
   const int n = rand()%10;      //generate a random size of the array

   int heap_arr[n];

   for (int i = 0; i < n; i++) 
      heap_arr[i] = rand() % 500 ;     // generate a random number between 0 and 499
   

   */
   
   //Create a vector array
   vector<int> vector_arr;
   //Element 
   int element;

   cout<<"Input array"<<endl;
   cout << "Enter '.' to stop : "<<endl;
   //Input array and stop inputting elements when '.' inputted
   while (cin>>element && element != '.') {
      vector_arr.push_back(element);
   }

   //Vector array size
   int n = vector_arr.size();
   //Create a heap array with the size of vector array
   int heap_arr[n];

   //Copying all elements of the vector array to the heap array
   copy(vector_arr.begin(),vector_arr.end(),heap_arr);

   //Output the inputted array
   cout<<"Inputted array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}