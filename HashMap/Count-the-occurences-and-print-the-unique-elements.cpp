class Solution {
public:
    int sumOfUnique(vector<int>& nums) 
    {
        map<int,int> mp;
        for(int x:nums)
        {
            mp[x]+=1;
        }
        
        int sum=0;
        for(auto x:mp)
        {
            if(x.second==1)
                sum+=x.first;
        }
        
        return sum;
    }
};