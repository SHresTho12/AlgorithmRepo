#include <iostream>
using namespace std;
void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
}

//Merge two part of the array or two lists
void mergeArrays(int FirstArray[], int startFirstPart, int mid, int lastOfSecondPart)
{
    int firstindex = startFirstPart, secondindex = mid + 1, mergeindex = startFirstPart;

    //Using temporary array to hold the merged values
    int mergedArray[lastOfSecondPart + 1];
    // Traverse both part of the array
    while (firstindex <= mid && secondindex <= lastOfSecondPart)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second part. If yes, store first
        // array element and increment first part
        // index. Otherwise do same with second part
        if (FirstArray[firstindex] < FirstArray[secondindex])
            mergedArray[mergeindex++] = FirstArray[firstindex++];
        else
            mergedArray[mergeindex++] = FirstArray[secondindex++];
    }
    // Store remaining elements of first array
    while (firstindex <= mid)
        mergedArray[mergeindex++] = FirstArray[firstindex++];

    // Store remaining elements of second array
    while (secondindex <= lastOfSecondPart)
        mergedArray[mergeindex++] = FirstArray[secondindex++];

    //Copying merged values in targeted array
    for (int i = startFirstPart; i <= lastOfSecondPart; i++)
        FirstArray[i] = mergedArray[i];
}

//Just insted of calling the merge of array sub part fuction iterative ly we are calling it recursively
void recursiveMerge(int arr[], int low, int high)
{

    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        recursiveMerge(arr, low, mid);
        recursiveMerge(arr, mid + 1, high);
        mergeArrays(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n ";
    printArray(arr, n);

    recursiveMerge(arr, 0, n - 1);

    cout << "\nSorted array is \n ";
    printArray(arr, n);
    return 0;
}