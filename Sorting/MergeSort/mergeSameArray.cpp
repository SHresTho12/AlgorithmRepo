//This is a implementation of the concept merging two sorted array in a single sorted array.
#include<iostream>
using namespace std;
void print(int array[] , int length){
    for(int i = 0 ; i < length ; i++){
        cout<<array[i];
    }
}
void mergeArrays( int FirstArray[],int startFirstPart , int mid , int lastOfSecondPart){
    int firstindex = startFirstPart , secondindex = mid+1 , mergeindex = startFirstPart;

    //Using temporary array to hold the merged values
    int mergedArray[lastOfSecondPart+1];
    // Traverse both part of the array
    while(firstindex <= mid && secondindex <= lastOfSecondPart){
        // Check if current element of first
        // array is smaller than current element
        // of second part. If yes, store first
        // array element and increment first part
        // index. Otherwise do same with second part
        if(FirstArray[firstindex] < FirstArray[secondindex]) mergedArray[mergeindex++] = FirstArray[firstindex++];
        else mergedArray[mergeindex++] = FirstArray[secondindex++];

    }
     // Store remaining elements of first array
    while (firstindex <= mid)
        mergedArray[mergeindex++] = FirstArray[firstindex++];
 
    // Store remaining elements of second array
    while (secondindex<= lastOfSecondPart)
        mergedArray[mergeindex++] = FirstArray[secondindex++];

    //Copying merged values in targeted array
    for(int i = startFirstPart ; i <=lastOfSecondPart ; i++ ) FirstArray[i] = mergedArray[i];
}
int main(){
    int arr1[] = {1, 3, 5, 7 ,2, 4, 6, 8};
    int n1 = 0;
    int n2 = 7;
    int mid = n2/2;
    
    mergeArrays(arr1,n1,mid , n2);
    print(arr1,n2+1);
 

} 