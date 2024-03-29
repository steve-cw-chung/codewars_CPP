//implementation of quicksort

#include <iostream>

using namespace std;
 
int Partition(int * A, int start, int end) {
    int pivot = A[end];
    int pIndex = start;
    int temp;

    for(int i = start ; i < end ; i++){
        if(A[i]<=pivot){
            
            temp = A[pIndex];
            
            A[pIndex]=A[i];
            A[i]=temp;
            pIndex++;
        }
    }
    temp= A[pIndex];
    A[pIndex] = pivot;
    A[end] = temp;

    return pIndex;

}
void QuickSort(int *A,int start, int end){
    if(start<end){
        int partitionIndex = Partition(A,start,end);
        QuickSort(A,start,partitionIndex-1);
        QuickSort(A,partitionIndex+1,end);
    }
}

int main () {
    int A[] = {7,6,5,4,3,2,1,0};
      for(int i = 0 ; i < 8; i++){
        cout<<A[i] << " " ;
    }
    cout << endl;
    QuickSort(A,0,7);
    for(int i = 0 ; i < 8; i++){
        cout<<A[i] << " " ;
    }
    return 0;
}