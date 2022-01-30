#include <bits/stdc++.h>

using namespace std;

bool dp[10001][10001] = {false};
// s1-s2 = minimum
int minSubsetSumDP(int set[], int n, int w){

    for(int j=0;j<=w;j++) dp[0][j]=false;
    for(int i=0;i<=n;i++) dp[i][0]=true;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(set[i-1] <= j){
                dp[i][j] = dp[i-1][j-set[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans  = 0;
    for(int i=w;i>=0;i--){
        if(dp[n][i]){
            ans = i;
            break;
        }
    }
    return ans;
   
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int set[] = {10, 8, 11, 5};
    int sum = 0;
    int n = sizeof(set) / sizeof(set[0]);
    for(int i=0;i<n;i++) sum+=set[i];
    cout << sum-2*minSubsetSumDP(set, n, sum/2) << "\n";
    return 0;
}