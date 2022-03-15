#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int cutRodSingleArray(int arr[], int n){

    int s[n+1];
    s[0]=0;

    for(int i=1;i<=n;i++){
        int max_val = INT_MIN;
        for(int j=0;j<i;j++){
            max_val = max(max_val,arr[j]+s[i-j-1]);
        }
        s[i] = max_val;
    }
    return s[n];
}

int cutRodDP(int arr[], int len[], int n, int w){

    int t[n+1][w+1] = {0};

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            } else if(len[i-1]<=j){
                t[i][j] = max(arr[i-1] + t[i][j-len[i-1]],t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int cutRod(int arr[], int len[], int n, int w){
    if(n==0 || w==0){
        return 0;
    }

    if(len[n-1] <= w){
        dp[n][w] = max(arr[n-1]+cutRod(arr,len,n,w-arr[n-1]),cutRod(arr,len,n-1,w));
    }
    else{
        dp[n][w] = cutRod(arr,len,n-1,w);
    }

    return dp[n][w];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int w = 8;
    memset(dp,0,sizeof(dp));
    cout <<"Maximum Obtainable Value is "<<cutRod(arr, len, size, w) << "\n";
    cout <<"Maximum Obtainable Value is "<<cutRodDP(arr, len, size, w) << "\n";
    cout <<"Maximum Obtainable Value is "<<cutRodSingleArray(arr, size) << "\n";
    return 0;
}