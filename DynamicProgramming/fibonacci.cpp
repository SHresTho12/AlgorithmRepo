#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//To store the previously calculated fib numbers.The array can be as big as you want
int FibonacciNumber[100000];
//Keep track of which fibonacci is already calculated
int visited[100000];
//fibonacci function
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if(visited[n] == 1) return FibonacciNumber[n];


    visited[n] = 1;
    FibonacciNumber[n] = fib(n - 1) + fib(n - 2);
    return FibonacciNumber[n];
}

int main()
{
    //test case
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fib(n);
    }
    return 0;
}


//Important Links
//https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/