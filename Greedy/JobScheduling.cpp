sort(arr,arr+n,compare);
        
        int maxi=arr[0].dead;
        for(int i=1;i<n;i++)
            maxi=max(arr[i].dead,maxi);
            
        int slot[maxi+1];
        for(int i=0;i<maxi+1;i++)
            slot[i]=-1;
        
        int profit=0,count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>=1;j--)
            {
                if(slot[j]==-1)
                {
                    slot[j]=arr[i].id;
                    count+=1;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> res;
        res.push_back(count);
        res.push_back(profit);
        
        return res;