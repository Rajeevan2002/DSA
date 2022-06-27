class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> v;
        for(int i=0;i<costs.size();i++)
        {
            int cost=costs[i][1]-costs[i][0];
            v.push_back({cost,i});
        }
        
        sort(v.begin(),v.end());
        int n=costs.size();
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
            ans+=costs[v[i].second][1];
        }
        for(int i=n/2;i<n;i++)
        {
            ans+=costs[v[i].second][0];
        }
        
        return ans;
        
        
    }
};