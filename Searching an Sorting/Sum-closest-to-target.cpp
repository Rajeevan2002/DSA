class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int mini=INT_MAX;
        sort(nums.begin(),nums.end());
        int ans;
        for(int i=0;i<nums.size()-2;i++)
        {
            int st=i+1;
            int end=nums.size()-1;
            while(st<end)
            {
                int sum=nums[st]+nums[end]+nums[i];
                if(sum==target)
                    return sum;
                else if(sum>target)
                {
                    if(abs(target-sum)<mini)
                    {
                        ans=sum;
                        mini=abs(target-sum);
                    }
                    end--;
                }
                else
                {
                    if(abs(target-sum)<mini)
                    {
                        ans=sum;
                        mini=abs(target-sum);
                    }
                    st++;
                }
            }
        }
        
        return ans;
        
    }
};