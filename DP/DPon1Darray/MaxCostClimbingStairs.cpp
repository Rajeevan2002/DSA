class Solution {
public:
    int find(vector<int> cost, vector<int> &dp,int i)
    {
        if(i>=cost.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=cost[i]+max(find(cost,dp,i+1),find(cost,dp,i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(1000,-1);
        int sum1=find(cost,dp,0);
        int sum2=find(cost,dp,1);
        return min(sum1,sum2);
    }
};