class Solution {
public:
    bool isPalindrome(string s,int st,int end)
    {
        while(st<end)
        {
            if(s[st++]!=s[end--])
                return false;
        }
        return true;
    }
    int f(int idx,string s,vector<int> &dp)
    {
        if(idx==s.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int mincost=INT_MAX;
        for(int j=idx;j<s.size();j++)
        {
            
            if(isPalindrome(s,idx,j))
            {
                int cost=1+f(j+1,s,dp);
                mincost=min(cost,mincost);
            }
        }
        return dp[idx]=mincost;
    }
    int minCut(string s) 
    {
        vector<int> dp(s.size()+1,0);
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            int mincost=INT_MAX;
            for(int j=i;j<s.size();j++)
            {
            
                if(isPalindrome(s,i,j))
                {
                    int cost=1+dp[j+1];
                    mincost=min(cost,mincost);
                }
            }
            dp[i]=mincost;
 
            
        }
        return dp[0]-1;
        
    }
};




ANOTHER SOLUTION: -
class Solution {
public:
    vector<vector<int>> dp1;
	bool isPalindrome(string& s, int i, int j) {
		if (i >= j) return true;
		if (dp1[i][j] != -1) return dp1[i][j];
		if (s[i] == s[j]) return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
		return dp1[i][j] = false;
	}

    int f(int idx,string s,vector<int> &dp)
    {
        if(idx==s.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int mincost=INT_MAX;
        for(int j=idx;j<s.size();j++)
        {
            
            if(isPalindrome(s,idx,j))
            {
                int cost=1+f(j+1,s,dp);
                mincost=min(cost,mincost);
            }
        }
        return dp[idx]=mincost;
    }
    int minCut(string s) 
    {
        dp1.resize(s.size(),vector<int> (s.size(),-1));
        vector<int> dp(s.size()+1,0);
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            int mincost=INT_MAX;
            for(int j=i;j<s.size();j++)
            {
            
                if(isPalindrome(s,i,j))
                {
                    int cost=1+dp[j+1];
                    mincost=min(cost,mincost);
                }
            }
            dp[i]=mincost;
 
            
        }
        return dp[0]-1;
        
    }
};