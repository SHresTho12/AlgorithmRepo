#include<iostream>
using namespace std;
// A utility function to print an array of size n
void printArray(int array[] , int length){
    for(int i = 0 ; i < length ; i++){
        cout<<array[i];
    }
}
 void insertionSort(int array[] , int lengthOfArray){
     int i , j , swapElement;
     for(int i = 1 ; i < lengthOfArray ; i ++  ){
         int j = i - 1 ;
         int swapElement = array[i];
         /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
         while( array[j] > swapElement && j>-1){
             array[j+1] = array[j];
             j--;

         }
         array[j+1] = swapElement;
     }
 }
int main(){
int array[] = {11,13,7,2,6,9,4,5,10,3} , n = 10 ;
insertionSort(array , n);
print(array , n);
}


