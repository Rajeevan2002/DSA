#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool check(int i,vector<int> &colored,int v,vector<int> adj[])
    {
        if(colored[i]==-1)
            colored[i]=1;
            
        for(auto itr:adj[i])
        {
            if(colored[itr]==-1)
            {
                colored[itr]=1-colored[i];
                if(check(itr,colored,v,adj))
                    return true;
            }
            else if(colored[itr]==colored[i])
                return true;
        }
        return false;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colored(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(colored[i]==-1)
	        {
	            if(check(i,colored,V,adj))
	                return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends