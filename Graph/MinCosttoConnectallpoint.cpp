class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<vector<pair<int, int>>> graph(points.size());
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			graph[i].push_back({j, getDistance(points[i], points[j])});
			graph[j].push_back({i, getDistance(points[i], points[j])});

            }
        }
        
        vector<bool> visited(n, false);
        pq.push({0, 0});
        int ans = 0;
        while(!pq.empty()) {
            
            pair<int, int> p = pq.top();
            pq.pop();
            if(visited[p.second]) {
                continue;
            }
            
            visited[p.second] = true;
            
            int u = p.second;
            ans += p.first;
            for(auto nbr: graph[u]) {
                if(!visited[nbr.first]) {
                    pq.push({nbr.second, nbr.first});
                }    
            }
        }
        
        return ans;
    }
    
    int getDistance(vector<int>& v1, vector<int>& v2) {
        return abs(abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    }

};