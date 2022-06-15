What we have to do is compare the words and create a graph based on comparisions
Once after this is done, We have to perform normal topological sort either using DFS or BFS
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k) 
    {
        //code here
        vector<vector<int>> adj(k);
        vector<int> deg(k);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<dict[i-1].size() && j<dict[i].size();j++)
            {
                if(dict[i][j]!=dict[i-1][j])
                {
                    adj[dict[i-1][j]-'a'].push_back(dict[i][j]-'a');
                    deg[dict[i][j]-'a']++;
                    break;
                }    
            }
        }
        
        string ret="";
        queue<int>q;
        
        for(int i=0;i<k;i++)
        {
            if(deg[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int val=q.front();
            q.pop();
            char ch='a'+val;
            ret+=ch;
            for(auto itr:adj[val])
            {
                deg[itr]-=1;
                if(deg[itr]==0)
                    q.push(itr);
            }
        }
        return ret;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends