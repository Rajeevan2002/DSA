// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void find(int i,int j,vector<vector<int>> &m,int n,string &res,vector<string> &ans)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(res);
            return ;
        }
        
        if(i<0 || i>=n || j<0 || j>=n)
            return;
        
        m[i][j]=-1;
        if(i-1>=0 && m[i-1][j]==1)
        {
            res+='U';
            find(i-1,j,m,n,res,ans);
            res.pop_back();
        }
        
        if(i+1<n && m[i+1][j]==1)
        {
            res+='D';
            find(i+1,j,m,n,res,ans);
            res.pop_back();
        }
        
        if(j+1<n && m[i][j+1]==1)
        {
            res+='R';
            find(i,j+1,m,n,res,ans);
            res.pop_back();
        }
        
        if(j-1>=0 && m[i][j-1]==1)
        {
            res+='L';
            find(i,j-1,m,n,res,ans);
            res.pop_back();
        }
        m[i][j]=1;
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int count=0;
        if(m[n-1][n-1]==0 || m[0][0]==0)
            return {"-1"};
        string res="";
        vector<string> ans;
        find(0,0,m,n,res,ans);
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends