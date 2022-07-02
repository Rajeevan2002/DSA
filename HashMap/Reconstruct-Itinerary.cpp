class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
         unordered_map<string,multiset<string>> adj;
         for(auto x:tickets)
         {
             adj[x[0]].insert(x[1]);
         }
        
        vector<string> ans;
        stack<string> mystk;
        mystk.push("JFK");
        while(!mystk.empty())
        {
            string src=mystk.top();
            if(adj[src].size()==0)
            {
                mystk.pop();
                ans.push_back(src);
            }
            else
            {
                auto dst=adj[src].begin();
                mystk.push(*dst);
                adj[src].erase(dst);
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        
        return ans;
    }
};