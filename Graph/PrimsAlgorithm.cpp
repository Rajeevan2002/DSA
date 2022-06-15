// Firstly have three key to store the edge value
// PArent arry to stre the paretn
// MST array of type boolean to include a prticular node or not
// After this in priority queue insert the nodes in the form of (key,node)
// every time when an element is popped out of a priority queue mark the mst of the node as true
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> mst(V,false);
        vector<int> parent(V,-1);
        vector<int> key(V,INT_MAX);
        
        
        priority_queue< pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> > pq;
        key[0]=0;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            pq.pop();
            mst[node]=true;
            for(auto itr:adj[node])
            {
                int nd=itr[0];
                int wt=itr[1];
                if(wt<key[nd] && !mst[nd])
                {
                    parent[nd]=node;
                    pq.push({wt,nd});
                    key[nd]=wt;
                }
            }
        }
        
        int count=0;
        for(auto x:key)
            count+=x;
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends