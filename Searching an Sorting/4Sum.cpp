class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size()<4)
        {
            vector<vector<int>> temp;
            //temp.push_back(0);
            //res.push_back(temp);
            return temp;
        }
        
        if(nums.size()==4)
        {
            if(nums[0]==0 && nums[1]==0 && nums[2]==0 && nums[3]==0 && target==0)
            {
                vector<int> temp(4,0);        
                temp[0]=nums[0];
                        temp[1]=nums[1];
                        temp[2]=nums[2];
                        temp[3]=nums[3];
                        res.push_back(temp);
                return res;
            }
            
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int target2=target-nums[i]-nums[j];
                
                int left=j+1;
                int right=nums.size()-1;
                
                while(left<right)
                {
                    int twosum=nums[left]+nums[right];
                    if(twosum<target2)
                    {
                        left++;
                    }
                    else if(twosum>target2)
                    {
                        right--;
                    }
                    else
                    {
                        vector<int> temp(4,0);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[left];
                        temp[3]=nums[right];
                        res.push_back(temp);
                        while(nums[left]==temp[2] && left<right)
                            left++;
                        
                        while(nums[right]==temp[3] && left<right)
                            right--;
                    }
                }
                while(j+1<nums.size() && nums[j+1]==nums[j])
                    ++j;
            }
            while(i+1<nums.size() && nums[i+1]==nums[i])
                ++i;
        }
        
        return res;
    }
};