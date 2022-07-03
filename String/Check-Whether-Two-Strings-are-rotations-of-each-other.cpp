// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    void fillLps(vector<int> &lps,string str)
    {
        int i=1;
        int len=0;
        int n=str.size();
        while(i<n)
        {
            if(str[i]==str[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                {
                    len=lps[i-1];
                }
            }
        }
    }
    bool areRotations(string s1,string s2)
    {
        // Your code here
        string text=s1+s1;
        string pat=s2;
        vector<int> lps(pat.size(),0);
        fillLps(lps,pat);
        int n=text.size();
        int i=0,len=0;
        while(i<n)
        {
            if(pat[len]==text[i])
            {
                i++;
                len++;
            }
            
            if(len==pat.size())
            {
                return true;
                len=lps[len-1];
            }
            else if(i<n && pat[len]!=text[i])
            {
                if(len==0)
                    i++;
                else
                    len=lps[len-1];
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends