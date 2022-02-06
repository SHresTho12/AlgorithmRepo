//
// Created by User on 2/3/2022.
//


#include<bits/stdc++.h>
using namespace std;
string s1 , s2;


//For storing the visited nodes hostory
int dp[1001][1001];



int lcs(int i, int j){
    //Base Case
    if(i>=s1.length()  || j>=s2.length()) return 0;

    //DP visited array to prevent overlapping sub problem
    if( dp[i][j] != -1) return dp[i][j];


    //Recursive definition
    if(s1[i] == s2[j]) return dp[i][j] = 1+lcs(i+1 , j+1);
    else return dp[i][j]=max(lcs(i+1 ,j) , lcs(i,j+1));




}

void path_print(int i , int j){
    if(i>=s1.length() or j>= s2.length()) return;
    if(s1[i] == s2[j]){
        cout<<s1[i];
        path_print(i+1,j+1);
    }
    else{
        //checking which is the higher number will have the solution
        if(dp[i+1][j] > dp[i][j+1]){
            path_print(i+1,j);
        } else path_print(i,j+1);
    }
    return;
}



int main(){
    while(getline(cin,s1)){
        getline(cin,s2);

        memset(dp,-1,sizeof(dp));
        cout<< lcs(0,0) <<endl;
        path_print(0,0);
    }
}


//Algo
//First check the base case if the i/j gets bigger than s1/s2 that means there is no common char
//For the recursive def :
//if the s1[i] == s2[j] that means that we have found a common char,and so we will add 1 to the ans ans both the i and j will be incremented and the LCS func will be again called
//if the char is not same then we have we check for all the js for single i and  also all the i for single j and return the max value