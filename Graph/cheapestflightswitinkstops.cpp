class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int, int>>> adj(n);//to, price
        
        for (int i=0; i<flights.size(); i++){
            
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        vector<int> d(n, INT_MAX);
        vector<vector<int>> dis(n+1, vector<int>(k+1, INT_MAX));
                
        d[src] = 0;
        
        set<pair<int, pair<int, int>>> st; //{d, {city, stops}}
        
        for (int i=0; i<n; i++){
            
            st.insert({d[i], {i, -1}});
        }
        
        while(!st.empty()){
            
            int curr = (*st.begin()).second.first;
            int stops = (*st.begin()).second.second;
            int cost = (*st.begin()).first;
            
            d[curr] = min(d[curr], cost);
                 
            st.erase(st.begin());
            
            if (stops == k) continue;
            if (cost == INT_MAX) continue;
            
            for (int i=0; i<adj[curr].size(); i++){
                
                int to = adj[curr][i].first;
                int pr = adj[curr][i].second;
                   
                if (dis[to][stops+1] > cost + pr){
                        
                    st.erase({dis[to][stops+1], {to, stops+1}});
                    dis[to][stops+1] = cost + pr;
                    st.insert({cost + pr, {to, stops+1}});
                        
                }
            }
        }
        
        if (d[dst] == INT_MAX) return -1;
        
        return d[dst];
        
    
    }
};