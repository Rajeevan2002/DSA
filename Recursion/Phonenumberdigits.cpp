class Solution {
public:
    void find(map<char,string> mp,vector<string> &ans,string& res,string digits,int idx)
    {
        if(res.size()==digits.size())
        {
            ans.push_back(res);
            return;
        }
        
        
        for(int i=idx;i<digits.size();i++)
        {
            for(int j=0;j<mp[digits[idx]].size();j++)
            {
                res+=mp[digits[idx]][j];
                find(mp,ans,res,digits,i+1);
                res.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        map<char,string> mp;
        mp.insert({'2',"abc"});
        mp.insert({'3',"def"});
        mp.insert({'4',"ghi"});
        mp.insert({'5',"jkl"});
        mp.insert({'6',"mno"});
        mp.insert({'7',"pqrs"});
        mp.insert({'8',"tuv"});
        mp.insert({'9',"wxyz"});
        if(digits=="")
            return {};
        
        vector<string> ans;
        string res="";
        find(mp,ans,res,digits,0);
        return ans;
    }
};