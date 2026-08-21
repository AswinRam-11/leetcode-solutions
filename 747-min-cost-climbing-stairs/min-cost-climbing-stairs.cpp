class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=2; i<n+1; i++){
            dp[i][0]= cost[i-1]+min(dp[i-1][1],dp[i-1][0]);
            dp[i][1] = cost[i-2]+ min(dp[i-2][1],dp[i-2][0]);
        }
        return min(dp[n][0],dp[n][1]);
    }
};