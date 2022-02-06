//
// Created by User on 2/6/2022.
//
//Assuming the pivot is the first element of the array
#include <bits/stdc++.h>

using namespace std;
// A utility function to print an array of size n
void printArray(int array[] , int length){
    for(int i = 0 ; i < length ; i++){
        cout<<array[i]<<" ";
    }
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int A[] , int low , int high){

    int pivot = A[low];
    int i = low , j = high;
    do{
        //Finds the larger element than the pivot
        do{i++;}while(A[i]<=pivot);
        //Finds the smaller element than the pivot
        do{j--;}while(A[j]>pivot);

        if(i<j) swap(&A[i] , &A[j]);
    }while(i<j);
    swap(&A[low] , & A[j]);

    return j;


}

void quickSort(int A[] , int low, int high){
    int part;
    if(low<high){
        part = partition(A,low,high);
        quickSort(A,low,part);
        quickSort(A,part+1,high);
    }
}
int main(){
    int A[] = {11,13,7,12,16,9,24,5,10,3,INT16_MAX};
    int n = 11; //length of the array

    quickSort(A,0,10);


    printArray(A,n);

}