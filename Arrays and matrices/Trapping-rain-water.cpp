class Solution {
public:
    int trap(vector<int>& height) 
    {
        int ans=0;
        int leftmax=0,rightmax=0;
        int l=0,r=height.size()-1;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                leftmax<=height[l]?leftmax=height[l]:ans+=leftmax-height[l];
                l++;
            }
            else
            {
                rightmax<=height[r]?rightmax=height[r]:ans+=rightmax-height[r];
                r--;
            }
        }
        return ans;
        
    }
};


/*********************************************************************************************************************************/
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        left[0]=height[0];
        for(int i=1;i<n;i++)
            left[i]=max(left[i-1],height[i]);
        
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            right[i]=max(right[i+1],height[i]);
        
        int ans=0;
        for(int i=0;i<height.size();i++)
            ans+=min(left[i],right[i])-height[i];
        
        return ans;
    }
};