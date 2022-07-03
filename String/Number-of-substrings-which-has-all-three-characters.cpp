class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int i=0,j=0,res=0;
        int ans=0;
        vector<int> count={0,0,0};
        int n=s.size();
        
        while(i<n)
        {
            count[s[i]-'a']++;
            
            while(j<n && count[0] && count[1] && count[2])
            {
                count[s[j]-'a']--;
                ans+=1;
                j++;
                
            }
            i++;
            res+=ans;
        }
        return res;   
    }
};