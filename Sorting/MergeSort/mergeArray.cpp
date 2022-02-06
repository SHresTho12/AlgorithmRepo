//This is a implementation of the concept merging two sorted array in a single sorted array.
#include<iostream>
using namespace std;
void print(int array[] , int length){
    for(int i = 0 ; i < length ; i++){
        cout<<array[i];
    }
}
void mergeArrays( int FirstArray[],int secondArray[],int firstArrayLength , int secondArrayLengrth ,int mergedArray[]){
    int firstindex = 0 , secondindex = 0 , mergeindex =0;
    // Traverse both array
    while(firstindex < firstArrayLength && secondindex < secondArrayLengrth){
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if(FirstArray[firstindex] < secondArray[secondindex]) mergedArray[mergeindex++] = FirstArray[firstindex++];
        else mergedArray[mergeindex++] = secondArray[secondindex++];

    }
     // Store remaining elements of first array
    while (firstindex < firstArrayLength)
        mergedArray[mergeindex++] = FirstArray[firstindex++];
 
    // Store remaining elements of second array
    while (secondindex< secondArrayLengrth)
        mergedArray[mergeindex++] = secondArray[secondindex++];
}
int main(){
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    int arr3[n1+n2];
    mergeArrays(arr1, arr2, n1, n2, arr3);
    print(arr3,n1+n2);
 

} 