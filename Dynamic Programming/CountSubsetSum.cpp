#include <bits/stdc++.h>

using namespace std;

int dp[10001][10001];

int countSubsetSumDP(int set[], int n, int w){
    vector<vector<int>> vec(n+1,vector<int>(w+1,-1));
    
    for(int j=0;j<=w;j++) vec[0][j] = 0;
    for(int i=0;i<=n;i++) vec[i][0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(set[i-1] <= j){
                vec[i][j] = vec[i-1][j-set[i-1]] + vec[i-1][j];
            } else {
                vec[i][j] = vec[i-1][j];
            }
        }
    }
    return vec[n][w];
}

int countSubsetSum(int set[], int n, int w){
    if(w==0) return 1;
    if(n==0) return 0;
    
    if(dp[n][w]!=-1) return dp[n][w];
    
    if(set[n-1] <=w){
        return dp[n][w] = countSubsetSum(set,n-1,w-set[n-1]) + countSubsetSum(set,n-1,w);
    }
    else{
        return dp[n][w] = countSubsetSum(set,n-1,w);
    }
    
    return dp[n][w];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 5;
    int n = sizeof(set) / sizeof(set[0]);
    cout << countSubsetSum(set, n, sum) << "\n";
    cout << countSubsetSumDP(set, n, sum) << "\n";
    return 0;
}