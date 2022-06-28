class Solution {
public:
    bool isSafe(vector<string> board,int row,int col,int n)
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
    void find(int col,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(board,row,col,n))
            {
                board[row][col]='Q';
                find(col+1,board,ans,n);
                board[row][col]='.';
            }
            
        }
    }
    
    int totalNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        
        find(0,board,ans,n);
        return ans.size();
        
    }
};