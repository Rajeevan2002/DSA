class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        
        for(int j=n-1;j>=0;j--)
        {
            dp[n-1][j]=triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);       
            }
        }
        return dp[0][0];
    }
};