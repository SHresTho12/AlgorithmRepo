//
// Created by User on 2/3/2022.
//

#include<bits/stdc++.h>
using namespace std;

int c[]={2,5,9,13,15,25,6,30,12,50};
int dp[100][100];
int n;

int coinCount(int i , int need){

    if(need == 0) return 0;
    if(i == n or need < 0) return INT16_MAX;
    if(dp[i][need] != -1) return dp[i][need];




    return dp[i][need] = min(1+ coinCount(i+1,need-c[i]) , coinCount(i+1,need));




}




int main(){

    memset(dp,-1,sizeof(dp));
    n = 10;
    cout<< coinCount(0 , 61)<<endl;



}

//Algo
//Assume coin is taken for one branch and not taken for another branch
//Calculate for both cases
//the min result is the result