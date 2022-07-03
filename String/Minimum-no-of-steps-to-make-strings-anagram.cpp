class Solution {
public:
    int minSteps(string s, string t) 
    {
        vector<int> mp(26,0);
        
        
        for(int i=0;i<s.size();i++)
            mp[s[i]-'a']++;
        
        for(int i=0;i<t.size();i++)
            mp[t[i]-'a']--;
        
        int count=0;
        for(int i=0;i<26;i++)
            count+=abs(mp[i]);
        
        return count/2;
        
    }
};