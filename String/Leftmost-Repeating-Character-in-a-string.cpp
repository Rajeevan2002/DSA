char firstRep (string s)
    {
        //code here.
        vector<int> mp(26,-1);
        int res=INT_MAX;
        
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(mp[ch-'a']!=-1)
            {
                res=min(res,mp[ch-'a']);
                continue;
            }
            mp[ch-'a']=i;
                
        }
        if(res==INT_MAX)
            return '#';
        return s[res];
    }