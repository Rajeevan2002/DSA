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
    void f(int idx,string s,vector<string> &path,vector<vector<string>> &ans)
    {
        if(idx==s.size())
        {
            ans.push_back(path);
            return;
        }
        
        for(int i=idx;i<s.size();i++)
        {
            if(isPalindrome(s,idx,i))
            {
                path.push_back(s.substr(idx,i-idx+1));
                f(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<string> path;
        vector<vector<string>> ans;
        f(0,s,path,ans);
        return ans;
        
    }
};