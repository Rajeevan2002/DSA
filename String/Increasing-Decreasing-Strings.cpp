class Solution {
public:
    string sortString(string s) 
    {
        vector<int> mp(26,0);
        
        string res="";
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']+=1;
        }
        
        int count=s.size();
        bool flag=true;
        while(count)
        {
            if(flag)
            {
                for(int i=0;i<26;i++)
                {
                    if(mp[i]>0)
                    {
                        res+=(i+'a');
                        mp[i]--;
                        count--;
                    }
                }    
            }
            else
            {
                for(int i=25;i>=0;i--)
                {
                    if(mp[i]>0)
                    {
                        res+=(i+'a');
                        count--;
                        mp[i]--;
                    }
                }
            }
            
            flag=!flag;
            
        }
        
        return res;
        
    }
};