class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        
        dist[S]=0;
        pq.push({0,S});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            int disti=it.first;
            int node=it.second;
            pq.pop();
            for(auto itr:adj[node])
            {
                int nodee=itr[0];
                int weight=itr[1];
                if(dist[nodee]>disti+weight)
                {
                    dist[nodee]=disti+weight;
                    pq.push({disti+weight,nodee});
                }
            }
        }
        
        return dist;
        
    }
};