class Solution {
public:
    int find(vector<vector<int>>& matrix, int i, int j,int n)
    {
        if(j>=n || j<0)
            return 1e9;
        
        if(i==0)
            return matrix[0][j];
        
        int s=matrix[i][j]+find(matrix,i-1,j,n);
        int lt=matrix[i][j]+find(matrix,i-1,j-1,n);
        int rt=matrix[i][j]+find(matrix,i-1,j+1,n);
        
        return min(s,min(lt,rt));
    }
    int minFallingPathSum(vector<vector<int>>& A) 
    {
        int ans=INT_MAX;
        int n=A.size();
        
        vector<vector<int> > dp(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++)
            dp[0][i]=A[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int val=A[i][j];
                
                int up=dp[i-1][j];
                int left=1e9;
                int right=1e9;
                if(j-1>=0)
                    left=dp[i-1][j-1];
                if(j+1<n)
                    right=dp[i-1][j+1];
                
                dp[i][j]=val+min(up,min(left,right));
            }
        }
        
        for(int i=0;i<n;i++)
            ans=min(ans,dp[n-1][i]);
        return ans;
        
    }
};