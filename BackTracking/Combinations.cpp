class Solution {
public:
    void find(vector<int> &res,vector<vector<int>> &ans,int idx,int k,int n)
    {
        if(res.size()==k)
            ans.push_back(res);
        for(int i=idx;i<=n;i++)
        {
            res.push_back(i);
            find(res,ans,i+1,k,n);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> res;
        vector<vector<int>> ans;
        find(res,ans,1,k,n);
        return ans;
    }
};