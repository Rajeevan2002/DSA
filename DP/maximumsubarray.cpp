class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
        }
        
        
        int curmax=1;
        int curmin=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                curmax=1;
                curmin=1;
                continue;
            }
            int temp=curmax*nums[i];
            curmax=max(nums[i]*curmax,max(nums[i]*curmin,nums[i]));
            curmin=min(temp,min(nums[i]*curmin,nums[i]));
            maxi=max(curmax,maxi);
        }
        
        return maxi;
        
    }
};