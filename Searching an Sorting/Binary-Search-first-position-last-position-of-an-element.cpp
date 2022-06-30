class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int ans1=-1;
        int ans2=-1;
        //To Find the First ELement in the given array
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans1=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
        }
        //To Find the Lasst ELement in the given array
        low=0;
        high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans2=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
        }
        
        vector<int> res;
        res.push_back(ans1);
        res.push_back(ans2);
        
        return res;
    }
};