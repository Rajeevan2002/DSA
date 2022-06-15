class Solution {
public:
    struct node
    {
        int u;
        int v;
        int wt;
        node(int first,int second,int weight)
        {
            u=first;
            v=second;
            wt=weight;
        }
            
    };
    static bool cmp(node a,node b)
    {
        return a.wt<b.wt;
    }
    int getDistance(vector<int>& v1, vector<int>& v2) 
    {
        return abs(abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    }
    int findParent(int nde,vector<int> &parent)
    {
        if(nde==parent[nde])
            return nde;
        return parent[nde]=findParent(nde,parent);
    }
    void unify(int u,int v,vector<int> &parent,vector<int> &rank)
    {
        u=findParent(u,parent);
        v=findParent(v,parent);
        
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[v]<rank[u])
        {
            parent[v]=u;
        }
        else
        {
            parent[v]=u;
            rank[u]+=1;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
	    vector<node> edges;

	    
	    for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			edges.push_back(node(i,j,getDistance(points[i], points[j])));
            // edges.push_back(node(j,i,getDistance(points[i], points[j])));
            }
        }
        
        sort(edges.begin(),edges.end(),cmp);
        int cost=0;
        vector<int> parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        vector<int> rank(n,0);
        
        vector<pair<int,int>> ans;
        for(auto itr:edges)
        {
            cout<<itr.u<<" "<<itr.v<<" "<<itr.wt<<endl;
            if(findParent(itr.u,parent)!=findParent(itr.v,parent))
            {
                cost+=itr.wt;
                ans.push_back({itr.u,itr.v});
                unify(itr.u,itr.v,parent,rank);
            }
        }
        return cost;
    }
    
    

};