class Solution{
public:
    int find(vector<int>nums)
    { 
        int low=0;
        int high=nums.size()-1;
        int ans1=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==1)
            {
                ans1=mid;
                high=mid-1;
            }
            else if(nums[mid]>1)
            {
                high=mid-1;
            }
            else if(nums[mid]<1)
            {
                low=mid+1;
            }
        }
        
        return ans1;
        
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m)
	{
	    
	    // code here
	    int ans=0;
	    int max_ind=-1;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i][m-1]==0)
	            continue;
	        if(arr[i][0]==arr[i][m-1] && arr[i][0]==1)
	            return i;
	        int val=m-find(arr[i]);
	        if(val>ans)
	        {
	            ans=val;
	            max_ind=i;
	        }
	    }
	    return max_ind;
	}

};


/*************************************************************************************************************************/
int rowWithMax1s(bool mat[R][C])
{
    // Initialize first row as row with max 1s
    int j,max_row_index = 0;
    j = C - 1;
 
    for (int i = 0; i < R; i++) {
        // Move left until a 0 is found
      bool flag=false; //to check whether a row has more 1's than previous
        while (j >= 0 && mat[i][j] == 1) {
            j = j - 1; // Update the index of leftmost 1
                       // seen so far
          flag=true ;//present row has more 1's than previous
          }
      // if the present row has more 1's than previous
      if(flag){
            max_row_index = i; // Update max_row_index
        }
    }
      if(max_row_index==0&&mat[0][C-1]==0)
            return -1;
    return max_row_index;
}