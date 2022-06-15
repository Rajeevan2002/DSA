class Solution {
public:
    void find(int s,int d,vector<vector<int>> &ans,vector<bool> visited,vector<int> &v,vector<vector<int>>adj)
    {
        if(s==d)
        {
            v.push_back(d);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        
        for(auto itr:adj[s])
        {
            visited[s]=true;
            v.push_back(s);
        
            if(!visited[itr])
            {
                find(itr,d,ans,visited,v,adj);
            }
            visited[s]=false;
            v.pop_back();
        
        }
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<int> v;
        vector<vector<int>> ans;
        vector<bool> visited(graph.size(),false);    
        
        find(0,graph.size()-1,ans,visited,v,graph);
        return ans;   
    }
};