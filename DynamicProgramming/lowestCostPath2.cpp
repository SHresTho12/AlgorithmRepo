
//For this we assume the walker can go not only one cell up or right but also diagonal
//https://www.geeksforgeeks.org/min-cost-path-dp-6/
#include <bits/stdc++.h>
using namespace std;

//For now we are thinking that  the matrix is of  21 by 21

int matrix[21][21];
int visited[21][21];

int cost[21][21] ={ {  1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3},
                    { 4, 8, 2 ,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,1,2,2},
                    { 1, 5, 3, 1, 5, 3, 1, 5, 3, 1, 5, 3,1, 5, 3,1, 5, 3,1, 5, 3},
                    {  1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3},
                    { 4, 8, 2 ,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,1,2,2},
                    { 1, 5, 3, 1, 5, 3, 1, 5, 3, 1, 5, 3,1, 5, 3,1, 5, 3,1, 5, 3},
                    {  1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3},
                    { 4, 8, 2 ,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,1,2,2},
                    { 1, 5, 3, 1, 5, 3, 1, 5, 3, 1, 5, 3,1, 5, 3,1, 5, 3,1, 5, 3},
                    {  1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3},
                    { 4, 8, 2 ,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,1,2,2},
                    { 1, 5, 3, 1, 5, 3, 1, 5, 3, 1, 5, 3,1, 5, 3,1, 5, 3,1, 5, 3},
                    {  1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3},
                    { 4, 8, 2 ,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,1,2,2},
                    { 1, 5, 3, 1, 5, 3, 1, 5, 3, 1, 5, 3,1, 5, 3,1, 5, 3,1, 5, 3},
                    {  1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3},
                    { 4, 8, 2 ,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,1,2,2},
                    { 1, 5, 3, 1, 5, 3, 1, 5, 3, 1, 5, 3,1, 5, 3,1, 5, 3,1, 5, 3},
                    {  1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3},
                    { 4, 8, 2 ,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,4, 8, 2,1,2,2},
                    { 1, 5, 3, 1, 5, 3, 1, 5, 3, 1, 5, 3,1, 5, 3,1, 5, 3,1, 5, 3}
};

int minimum(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}
int minCost(int i , int j){
    //Base case
    if(i==0 && j == 0) return cost[0][0];

    if(visited[i][j] == 1) return matrix[i][j];

    visited[i][j] = 1;

    //recursive definition
    int returnValue;
    if(i == 0) {
        returnValue = cost[i][j] + minCost(i, j - 1);
        //cout<<"I == 0"<<i<<j <<returnValue;
    }
    else if(j == 0){
        returnValue = cost[i][j] + minCost(i - 1, j);
        //cout<<"j ==0 "<<i<<j<<returnValue;
    }
    else {
        returnValue = cost[i][j] + minimum(minCost(i-1,j), minCost(i,j-1) , minCost(i-1,j-1));
        //cout<<"UN"<<i<<j<<returnValue;
    }

    matrix[i][j] = returnValue;
    return matrix[i][j];


}
int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {

        int x,y;
        cout<<"Enter the cell number :"<<endl;
        cin>>x>>y;
        cout<<"Ans : "<<minCost(x,y);


    }
}
