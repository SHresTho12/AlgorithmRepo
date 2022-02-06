//
// Created by User on 2/3/2022.
//
//Coin change version 2
//Here instead of using one coin once all the coins can be used infinite amount of time.
#include<bits/stdc++.h>
using namespace std;

int c[]={2,5,9,13,15,25,6,30,12,50};
int dp[100];
int n;

int coinCount( int need){

    if(need == 0) return 0;
    if(need < 0) return INT16_MAX;
    if(dp[need] != -1) return dp[need];
    int ans = INT16_MAX;

    for(int i = 0 ; i < n ; i++){
        ans = min(ans,1+ coinCount(need-c[i]));
    }

    return dp[need]=ans;

}




int main(){

    memset(dp,-1,sizeof(dp));
    n = 10;
    cout<< coinCount( 60)<<endl;



}

//Algo
//Assume coin is taken for one branch and not taken for another branch
//Calculate for both cases
