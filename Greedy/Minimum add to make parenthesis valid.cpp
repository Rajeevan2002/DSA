class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int notopened=0,notclosed=0;
        for(char ch:s)
        {
            if(ch=='(')
                notclosed+=1;
            else if(notclosed>0)
                notclosed-=1;
            else
                notopened+=1;
        }
        
        return notopened+notclosed;
        
    }
};


int minAddToMakeValid(string s) 
    {
        stack<char> st;
        int count=0;
        for(char ch:s)
        {
            if(ch=='(')
            {
                st.push(ch);
            }
            else if(!st.empty())
            {
                st.pop();
            }
            else
                count+=1;
        }
        while(!st.empty())
            count+=1,st.pop();
        return count;
        
    }