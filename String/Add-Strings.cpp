class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        string n1=num1;
        string n2=num2;
        
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        
        int i=0,j=0;
        
        int carry=0;
        string res="";
        while((i<num1.size() || j<num2.size()) || carry)
        {
            int sum=0;
            if(i<n1.size())
            {
                sum+=(n1[i]-'0');
                i++;
            }
            if(j<n2.size())
            {
                sum+=(n2[j]-'0');
                j++;
            }
            sum+=carry;
            res+=((sum%10)+'0');
            carry=sum/10;
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};