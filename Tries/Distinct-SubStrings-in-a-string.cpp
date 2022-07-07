// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}

// } Driver Code Ends


/*You are required to complete this method */
struct Node
{
    Node* links[26];
    void put(char ch,Node* nde)
    {
        links[ch-'a']=nde;
    }
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
};
int countDistinctSubstring(string s)
{
    //Your code here
    int ans=0;
    Node* root=new Node();
    
    for(int i=0;i<s.size();i++)
    {
        Node* nde=root;
        for(int j=i;j<s.size();j++)
        {
            if(!nde->containsKey(s[j]))
            {
                ans++;
                nde->put(s[j],new Node());
            }
            nde=nde->get(s[j]);
        }
    }
    
    return ans+1;
}