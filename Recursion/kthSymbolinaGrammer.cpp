class Solution {
public:
    int f(int n,int k)
    {
        if(n==1)
            return 0;
        int par=f(n-1,k/2+(k%2));
        bool isOdd= (k%2==1);
        if(par==1)
        {
            if(isOdd)
                return 1;
            return 0;
        }
        else
        {
            if(isOdd)
                return 0;
            return 1;
        }
        
    }
    int kthGrammar(int n, int k) 
    {
        return f(n,k);
    }
};