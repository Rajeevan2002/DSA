class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l=0;
        int r=0;
        unordered_map<char,int> mp;
        int res=0;
        
        while(r<s.size())
        {
            char ch=s[r];
            if(mp.count(ch))
            {
                l=max(l,mp[ch]+1);
            }
            mp[ch]=r;
            res=max(res,r-l+1);
            r++;
        }
        
        return res;
        
    }
};