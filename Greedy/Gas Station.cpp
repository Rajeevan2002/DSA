int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        vector<int> diff(gas.size());
        int _gas=0;
        for(int x:gas)
            _gas+=x;
        
        int _cost=0;
        for(int x:cost)
            _cost+=x;
        
        if(_gas<_cost)
            return -1;
        
        for(int i=0;i<gas.size();i++)
        {
            diff[i]=gas[i]-cost[i];
        }
        
        int ans=0;
        int curr=0;
        for(int i=0;i<diff.size();i++)
        {
            
            if(curr<0)   
            {
                curr=0;
                ans=i;
            }
            curr+=diff[i];
        }
        
        return ans;