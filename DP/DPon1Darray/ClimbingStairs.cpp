class Solution {
public:
    int climbStairs(int n) 
    {
        if(n<=3)
            return n;
        
        int a=2;
        int b=3;
        n-=3;
        int sum=0;
        while(n>0)
        {
            sum=a+b;
            a=b;
            b=sum;
            n--;
        }
        return sum;
    }
};