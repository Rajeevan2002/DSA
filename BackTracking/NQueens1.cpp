class Solution {
public:
    bool isSafe(vector<string> board,int row ,int col,int n)
    {
        int duprow=row;
        int dupcol=col;
        
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        row=duprow;
        col=dupcol;
        
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        col=dupcol;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int j,vector<string> &v,vector<vector<string>> &ans,int n)
    {
        if(j==n)
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(v,i,j,n))
            {
                v[i][j]='Q';
                solve(j+1,v,ans,n);
                v[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<vector<string>> ans ;
        solve(0,board,ans,n);
        
        return ans;
    }
};