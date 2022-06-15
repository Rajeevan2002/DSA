class Solution {
public:
    bool check(vector<vector<char>>& board,int i,int j,int n,string word)
    {
        if(n==word.size())
            return true;
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='*'|| board[i][j]!=word[n])
            return false;
        
        char ch=board[i][j];
        board[i][j]='*';
        bool dfs=check(board,i+1,j,n+1,word)|check(board,i,j+1,n+1,word)|check(board,i-1,j,n+1,word)|check(board,i,j-1,n+1,word);
        
        board[i][j]=ch;
        return dfs;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        vector<vector<bool>> visited(board.size(),vector<bool> (board[0].size(),false));
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(word[0]==board[i][j] && check(board,i,j,0,word))
                    return true;
            }
        }
        return false;
    }
};