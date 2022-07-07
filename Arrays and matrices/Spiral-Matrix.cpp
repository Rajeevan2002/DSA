class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> v;
        int n=matrix.size();
        int m=matrix[0].size();
        
        int r_start=0,c_start=0;
        int r_end=n-1,c_end=m-1;
        
        while(r_start<=r_end && c_start<=c_end)
        {
            for(int col=c_start;col<=c_end;col++)
                v.push_back(matrix[r_start][col]);
            r_start++;
            for(int row=r_start;row<=r_end;row++)
                v.push_back(matrix[row][c_end]);
            c_end--;
            for(int col=c_end;col>=c_start;col--)
                v.push_back(matrix[r_end][col]);
            r_end--;
            for(int row=r_end;row>=r_start;row--)
                v.push_back(matrix[row][c_start]);
            c_start++;
        }
         vector<int> res;
        for(int i=0;i<n*m;i++)
            res.push_back(v[i]);
        return res;
        
        
    }
};