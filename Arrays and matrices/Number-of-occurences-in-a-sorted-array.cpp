int count(int arr[], int n, int x) {
	    // code here
	    int first=-1;
	    int last=-1;
	    
	    int l=0;
	    int r=n-1;
	    
	    while(l<=r)
	    {
	        int mid=l+(r-l)/2;
	        if(arr[mid]==x)
	        {
	            first=mid;
	            r=mid-1;
	        }
	        else if(arr[mid]>x)
	        {
	            r=mid-1;
	        }
	        else
	            l=mid+1;
	    }
	    
	    l=0;
	    r=n-1;
	    
	    while(l<=r)
	    {
	        int mid=l+(r-l)/2;
	        if(arr[mid]==x)
	        {
	            last=mid;
	            l=mid+1;
	        }
	        else if(arr[mid]>x)
	        {
	            r=mid-1;
	        }
	        else
	            l=mid+1;
	    }
	    if(last==-1 && first==-1)
	        return 0;
	    return last-first+1;
	}