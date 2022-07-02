class Solution {
public:
    bool check(vector<int> a,vector<int> b)
    {
        int i=0;
        while(i<26)
        {
            if(a[i]!=b[i])
            {
                
                return false;
            }
            i++;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) 
    {
         vector<int> res;
        if(s.size()<p.size())
            return res;
        vector<int> vict(26,0);
        for(int i=0;i<p.size();i++)
            vict[(p[i]-'a')]+=1;
        
        vector<int> word(26,0);
        for(int i=0;i<p.size();i++)
            word[(s[i]-'a')]+=1;
        
        int m=p.size();
        if(check(word,vict))
            res.push_back(0);
        for(int i=m;i<s.size();i++)
        {
            
            
            ++word[s[i]-'a'];
            --word[s[i-m]-'a'];
            
            if(check(vict,word))
                res.push_back(i-m+1);
        }
        
        return res;        
    }
};