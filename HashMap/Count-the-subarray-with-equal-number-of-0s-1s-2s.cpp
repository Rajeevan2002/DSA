// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    typedef long long ll;
    long long getSubstringWithEqual012(string str) {
        // code here
        int zc=0;
        int oc=0;
        int tc=0;
        
        int res=0;
        map<pair<int,int>,int> mp;
        mp[{0,0}]=1;
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='0')
                zc++;
            else if(str[i]=='1')
                oc++;
            else
                tc++;
                
            
            auto temp=make_pair(zc-oc,zc-tc);
            
            res+=mp[temp];
            mp[temp]+=1;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}
  // } Driver Code Ends