 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums1.size();i++)
            mp[nums1[i]]=i;
        
        stack<int> str;
        int n=nums2.size();
        vector<int> a(nums1.size(),-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!str.empty() && str.top()<=nums2[i])
                str.pop();
            
            if(mp.find(nums2[i])!=mp.end())
            {
                   auto x=mp.find(nums2[i]);
                   if(str.empty())
                       a[x->second]=-1;
                    else
                        a[x->second]=str.top();
            }
            str.push(nums2[i]);
        }
        
        return a;
        
        
    }