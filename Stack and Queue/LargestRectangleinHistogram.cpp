class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
        stack<pair<int,int>> st;
        for(int i=0;i<heights.size();i++)
        {
            int start=i;
            while(!st.empty() && st.top().second>heights[i])
            {
                auto x=st.top();
                int idx=x.first;
                st.pop();
                int height=x.second;
                maxarea=max(maxarea,height*(i-idx));
                start=idx;
            }
            st.push({start,heights[i]});
        }
        int n=heights.size();
        
        while(!st.empty())
        {
            auto x=st.top();
            int idx=x.first;
            int height=x.second;
            maxarea=max(maxarea,height*(n-idx));
            st.pop();
        }
        
        return maxarea;
            
    }
};