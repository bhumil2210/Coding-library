#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

int knapSack(int w, int wt[], int val[], int n){
    
    if(n==0 || w==0){
        return 0;
    }
    
    if(dp[n][w]!=0){
        return dp[n][w];
    }
    
    if(w >= wt[n-1]){
        return dp[n][w] = max(val[n-1]+knapSack(w-wt[n-1],wt,val,n-1),knapSack(w,wt,val,n-1));
    }
    else{
        return dp[n][w] = knapSack(w,wt,val,n-1);
    }
    
}

int topdownkS(int w, int wt[], int val[], int n){
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    memset(dp,0,sizeof(dp));
    printf("%d\n", knapSack(W, wt, val, n));
    printf("%d\n", topdownkS(W, wt, val, n));
    return 0;
}