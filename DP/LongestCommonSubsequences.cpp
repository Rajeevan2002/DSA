class Solution {
public:
    int f(string s1,string s2,int idx1,int idx2,vector<vector<int>> &dp)
    {
        if(idx1<0 || idx2<0)
            return 0;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2])
        {
            return dp[idx1][idx2]=1+f(s1,s2,idx1-1,idx2-1,dp);
        }
        
        return dp[idx1][idx2]=max(f(s1,s2,idx1-1,idx2,dp),f(s1,s2,idx1,idx2-1,dp));
    }
    int longestCommonSubsequence(string s1, string s2) 
    {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int idx1=0;idx1<n;idx1++)
        {
            for(int idx2=0;idx2<m;idx2++)
            {
                if(s1[idx1]==s2[idx2])
                {
                    dp[idx1+1][idx2+1]=1+dp[idx1][idx2];
                    continue;
                }
                dp[idx1+1][idx2+1]=max(dp[idx1][idx2+1],dp[idx1+1][idx2]);
            }
        }
        return dp[n][m];
    }
};