class Solution {
private:
    int count;
   
    void checkCount(vector<int>& nums, int start, int mid, int end){

        // two pointers;
        int l = start, r = mid + 1;
        while(l <= mid && r <= end){
            if((long)nums[l] > (long) 2 * nums[r]){
                count += (mid - l + 1);
                r++;
            }else{
                l++;
            }
        }
       // worst case might be nlog(n) 
        sort(nums.begin() + start, nums.begin() + end + 1);
        return;
        
        
        
        //every step sort
    }
    void mergeSort(vector<int>& nums, int start, int end){
        if(start == end) return;
        
        int mid = (start + end)/2;
        mergeSort(nums,start, mid);
        mergeSort(nums,mid+1,end);
        
        checkCount(nums,start,mid,end);
        return;
        
    }
public:
    int reversePairs(vector<int>& nums) {
        if(!nums.size())return 0;
        count = 0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};




/***********************************************************************************************************************************************************************/

long long int merge(long long int arr[],long long int temp[],long long int left,long long int mid,long long int right)
    {
        long long int inv=0;
        
        long long int i=left;
        long long int j=mid;
        long long int k=left;
        
        while(i<mid && j<=right)
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++]=arr[j++];
                inv+=mid-i;
            }
        }
        
        while(i<mid)
            temp[k++]=arr[i++];
        
        while(j<=right)
            temp[k++]=arr[j++];
            
        for(i=left;i<=right;i++)
            arr[i]=temp[i];
            
        return inv;
        
    }
    long long int mergeSort(long long int arr[],long long int temp[],long long int left,long long int right)
    {
        long long int inv=0;
        if(right>left)
        {
            int mid=(left+right)/2;
            inv+=mergeSort(arr,temp,left,mid);
            inv+=mergeSort(arr,temp,mid+1,right);
            
            inv+=merge(arr,temp,left,mid+1,right);
        }
        return inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int temp[N];
        long long int invcount=mergeSort(arr,temp,0,N-1);
        return invcount;
    }

    
