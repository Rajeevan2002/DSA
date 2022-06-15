bool isCyclic_Util(vector<vector<int>>& adj, vector<int>& vis, int curr){
    if(vis[curr] == 2)
        return true;
    
    vis[curr] = 2;
    for(int i=0; i<adj[curr].size(); i++){
        if(vis[adj[curr][i]] != 1 and isCyclic_Util(adj, vis, adj[curr][i]))
            return true;
    }
    
    vis[curr] = 1;
    return false;
}

bool isCyclic(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<n; i++)
            adj[pre[i][0]].push_back(pre[i][1]);
        
        vector<int> vis(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(vis[i] == 0 and isCyclic_Util(adj, vis, i)){
                return false;
            }
        }
        return true;
    }