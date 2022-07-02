class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int curr=0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            count+=mp[curr-k];
            mp[curr]+=1;
        }
        return count;
        
    }
};