// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    bool precedence(char ch1,char ch2)
    {
        map<char,int> mp;
        mp['^']=2;
        mp['*']=1;
        mp['/']=1;
        mp['+']=0;
        mp['-']=0;
        return mp[ch2]>=mp[ch1];
    }
    string infixToPostfix(string st) 
    {
        // Your code here
        unordered_map<char, int> mp;
        mp.insert({'^',3});
        mp.insert({'*', 2});
        mp.insert({'/', 2});
        mp.insert({'+', 1});
        mp.insert({'-', 1});
        mp.insert({'(', 0});
        stack<char> s;
        string res="";
        for(auto x:st)
        {
            if(isalpha(x))
                res+=x;
            else if(x=='(')
                s.push(x);
            else if(x==')')
            {
                while(s.top()!='(')
                {
                    res+=s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
                {
                    if(!s.empty())
                    {
                        if(s.top()!='(')
                        {
                            while(!s.empty() && mp[x] <= mp[s.top()])
                            {
                                res+=s.top();
                                s.pop();
                            }
                            s.push(x);
                        }
                        else
                            s.push(x);
                    }
                    else
                        s.push(x);
                }
            }
        }
        
        while(!s.empty())
        {
            res+=s.top();
            s.pop();
        }
        return res;
        
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends