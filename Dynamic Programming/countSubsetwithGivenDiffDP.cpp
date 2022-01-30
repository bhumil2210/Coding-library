#include <bits/stdc++.h>

using namespace std;

int dp[10001][10001];

int countSubsetwithGivenDiffDP(int set[], int n, int w){

    memset(dp,0,sizeof(dp));

    for(int j=0;j<=w;j++) dp[0][j]=false;
    for(int i=0;i<=n;i++) dp[i][0]=true;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(set[i-1] <= j){
                dp[i][j] = dp[i-1][j-set[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
   
}

// s1-s2 = K
// s1-(sum-s1)=k
// sum-2*s1=k
// s1 = (sum-k)/2

int main()
{
    memset(dp,-1,sizeof(dp));
    int set[] = {10, 8, 11, 5};
    int diff = 5,sum = 0;
    int n = sizeof(set) / sizeof(set[0]);
    for(int i=0;i<n;i++) sum+=set[i];
    cout << countSubsetwithGivenDiffDP(set, n, (sum-diff)/2) << "\n";
    return 0;
}