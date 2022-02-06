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
void iterativeMerge(int arr[], int n)
{
    int level, i, low, mid, high;
    // Merge subarrays in bottom up manner.  First merge subarrays of
    // size 1 to create sorted subarrays of size 2, then merge subarrays
    // of size 2 to create sorted subarrays of size 4, and so on.
    for (level = 2; level <= n; level = level * 2)
    {

        for (int i = 0; i + level - 1 < n; i = i + level)
        {

            //Find the staring of the sub array
            //Find the mid for the starting of the second sub array and the last position of the second sub array
            low = i;
            high = i + level - 1;
            mid = (low + high) / 2;
            mergeArrays(arr, low, mid, high);
        }
    }

    //if the array is not a size of a 2^n form there will be a sub array left behind
    if (level / 2 < n)
    {
        mergeArrays(arr, 0, level / 2 - 1, n - 1);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n ";
    printArray(arr, n);

    iterativeMerge(arr, n);

    cout << "\nSorted array is \n ";
    printArray(arr, n);
    return 0;
}