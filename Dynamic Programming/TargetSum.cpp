class Solution {
public:
    
    int solve(vector<int>& nums, int sum){
        int n = nums.size();
        int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        for(int j=0;j<=sum;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j){
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        
        return dp[n][sum];
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0,zero=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum < target || (sum-target)%2!=0) return 0;
        sum = (sum-target)/2;
        return solve(nums,sum);
    }
};


// s1-s2 = 3
// 5 - 2s1 = 3
// s1 = 1