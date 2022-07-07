int findMaxDiff(int A[], int n)
    {
      //Your code here
      stack<int> st;
      st.push(0);
      vector<int> ls(n,0);
      vector<int> rs(n,0);
      for(int i=1;i<n;i++)
      {
          while(!st.empty() && A[st.top()]>=A[i])
            st.pop();
            
          if(!st.empty())
            ls[i]=A[st.top()];
          st.push(i);
          
      }
      
      while(!st.empty())
        st.pop();
      st.push(n-1);
      for(int i=n-2;i>=0;i--)
      {
          while(!st.empty() && A[st.top()]>=A[i])
            st.pop();
         if(!st.empty())
            rs[i]=A[st.top()];
         st.push(i);
      }
      int ans=INT_MIN;
      for(int i=0;i<n;i++)
            ans=max(ans,abs(ls[i]-rs[i]));
         
        return ans;
    }