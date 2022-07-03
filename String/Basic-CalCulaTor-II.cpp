class Solution {
public:
    int calculate(string s) 
    {
        stack<int> st;
        char oper='+';
        int curr=0;
        int n=s.size();
        if(n==0)
            return 0;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(isdigit(ch))
            {
                curr=curr*10+(ch-'0');
            }
            if((!isdigit(ch) && !iswspace(ch)) || i==n-1)
            {
                if(oper=='+')
                    st.push(curr);
                if(oper=='-')
                    st.push(-curr);
                if(oper=='*')
                {
                    int topie=st.top();
                    st.pop();
                    st.push(topie*curr);
                }
                if(oper=='/')
                {
                    int topie=st.top();
                    st.pop();
                    st.push(topie/curr);
                }
                oper=ch;
                curr=0;
            }
        }
        
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        
        return sum;
    }
};