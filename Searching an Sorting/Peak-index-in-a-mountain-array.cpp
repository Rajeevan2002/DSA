class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid1=low+(high-low)/2;
            int mid2=mid1+1;
            if(arr[mid1]<arr[mid2])
            {
                ans=mid2;
                low=mid1+1;
            }    
            else
                high=mid1-1;
            
        }
        return ans;
        
    }
};