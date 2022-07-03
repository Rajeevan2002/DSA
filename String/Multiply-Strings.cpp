class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if(num1=="0" || num2=="0")
            return "0";
        
        int n1=num1.size();
        int n2=num2.size();
        vector<int> res(n1+n2,0);
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                int sum=(num1[i]-'0')*(num2[j]-'0');
                
                res[i+j]+=sum;
                res[i+j+1]+=res[i+j]/10;
                res[i+j]=res[i+j]%10;
            }
        }
        
        reverse(res.begin(),res.end());
        int i=0;
        while(res[i]==0)
            i++;
        
        string ans="";
        while(i<res.size())
            ans+=(res[i++]+'0');
        
        return ans;
        
    }
};