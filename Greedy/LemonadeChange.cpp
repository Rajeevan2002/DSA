class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int countfive=0;
        int countten=0;
        int counttwenty=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
                countfive+=1;
            else if(bills[i]==10)
            {
                countten+=1;
                if(countfive==0)
                    return false;
                countfive-=1;
            }
            else if(bills[i]==20)
            {
                counttwenty+=1;
                if(countten<1 && countfive<3)
                    return false;
                if(countten>0)
                {
                    if(countfive==0)
                        return false;
                    else
                    {
                        countten-=1;
                        countfive-=1;
                    }
                }
                else
                {
                    if(countfive>=3)
                    {
                        countfive-=3;
                    }
                }
            }
        }
        return true;
    }
};



int lemonadeChange(vector<int> bills) {
        int five = 0, ten = 0;
        for (int i : bills) {
            if (i == 5) five++;
            else if (i == 10) five--, ten++;
            else if (ten > 0) ten--, five--;
            else five -= 3;
            if (five < 0) return false;
        }
        return true;
    }