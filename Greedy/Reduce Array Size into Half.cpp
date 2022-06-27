class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        int count=0;
        int maxi=INT_MIN;
        map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            maxi=max(maxi,arr[i]);
            mp[arr[i]]+=1;
            count+=1;
        }
        
        vector<int> v;
        for(auto x:mp)
        {
            v.push_back(x.second);
        }
        
        sort(v.begin(),v.end(),greater<int>());
        
        int ans=0;
        int dummy=count;
        for(int i=0;i<v.size();i++)
        {
            
            if(count<=dummy/2)
                return ans;
            count-=v[i];
            ans+=1;
        }
        
        return ans;    
    }
};




