class Solution {
public:
    string countAndSay(int n) 
    {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        
        string s="11";
        for(int i=3;i<=n;i++)
        {
            s+="$";
            string temp="";
            int count=1;
            int num=s.size();
            for(int j=1;j<num;j++)
            {
                if(s[j]!=s[j-1])
                {
                    temp+=(count+'0');
                    temp+=s[j-1];
                    count=1;
                }
                else
                {
                    count+=1;
                }
            }
            s=temp;
        }
        
        return s;
        
    }
};