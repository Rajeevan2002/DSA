class Solution {
public:
    void f(int idx,vector<int> &res,vector<int> a,vector<vector<int>> &ans,int target,int &sum)
    {
        if(sum==target)
        {
            ans.push_back(res);
            return;
        }
        if(idx>=a.size())
            return;
        if(sum<target)
        {
            sum+=a[idx];
            res.push_back(a[idx]);
            f(idx,res,a,ans,target,sum);
            sum-=a[idx];
            res.pop_back();
        }
        f(idx+1,res,a,ans,target,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> res;
        sort(candidates.begin(),candidates.end());
        int sum=0;
        f(0,res,candidates,ans,target,sum);
        return ans;
        
    }
};