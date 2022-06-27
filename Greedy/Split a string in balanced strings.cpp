class Solution {
public:
    int balancedStringSplit(string s) 
    {
        int left=0;
        int right=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='L')
                left+=1;
            else
            {
                left-=1;
            }
            if(left==0)
                right+=1;
        }
        
        return right;
        
    }
};