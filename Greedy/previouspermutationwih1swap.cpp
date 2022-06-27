class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) 
    {
        int i=arr.size()-2,n=-1;
        while(i>=0 && arr[i]<=arr[i+1])
            i--;
        if(i>=0)
        {
            n=i+1;
            for(int j=n+1;j<arr.size();j++)
                if(arr[n] < arr[j] && arr[j]<arr[i])
                    n=j;
            swap(arr[n],arr[i]);
                    
        }
        return arr;
        
    }
};