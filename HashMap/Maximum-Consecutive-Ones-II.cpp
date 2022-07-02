class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int i=0,j=0,count=0;
        int res=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                count+=1;
            
            while(count>k && j<nums.size())
            {
                if(nums[j]==0)
                    count--;
                j++;
            }
            
            res=max(res,i-j+1);
        }
        return res;
    }
};