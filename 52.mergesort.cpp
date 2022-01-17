//implementation of mergesort

#include <iostream>
using namespace std;


void merge(int array[], int const left, int const mid, int const right){
    //merge 2 subarrays 
    // first array : arr[begin...mid]
    // second array : arr[mid+1...end]
    int sizeOfLeft = mid-left+1;
    int sizeOfRight = right-mid;

    // create temp arrays
    int* leftArr = new int[sizeOfLeft];
    int* rightArr = new int[sizeOfRight];

    for(int i = 0; i < sizeOfLeft ; i++){
        leftArr[i] = array[left+i];
    }
    for(int i=0; i < sizeOfRight ; i++){
        rightArr[i] = array[i+mid+1];
    }

    int indexOfLeft = 0; // Initial index of left
    int indexOfRight = 0; // Initial index of right
    int indexOfSorted = left; // Initial index of sorted 

    while(indexOfLeft<sizeOfLeft && indexOfRight < sizeOfRight){
        if(leftArr[indexOfLeft]<=rightArr[indexOfRight]){
            array[indexOfSorted] = leftArr[indexOfLeft];
            indexOfLeft++;
        } else {
            array[indexOfSorted] = rightArr[indexOfRight];
            indexOfRight++;
        }
        indexOfSorted++;
    }
    //Handle Left over numbers
    while(indexOfLeft<sizeOfLeft){
        array[indexOfSorted] = leftArr[indexOfLeft];
        indexOfSorted++;
        indexOfLeft++;
    }
    while(indexOfRight<sizeOfRight){
        array[indexOfSorted] = rightArr[indexOfRight];
        indexOfSorted++;
        indexOfRight++;
    }
}
void mergeSort(int array[], int const begin, int const end){
    // dividing the arrays into smaller pieces
    if (begin>=end) return;

    int mid = begin + (end-begin) / 2;

    mergeSort(array,begin,mid);
    mergeSort(array,mid+1,end);
    merge(array,begin,mid,end);

    

}
void printArray(int A[], int size){
    for (int i = 0 ; i < size ; i ++){
        cout << A[i] << " " ;
    }


}



int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
  
    cout << "Given array is \n";
    printArray(arr, arr_size);
  
    mergeSort(arr, 0, arr_size - 1);
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}