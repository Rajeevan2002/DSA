class Solution {
public:
    bool isVowel(char ch)
    {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) 
    {
        int count=0;
        for(int i=0;i<k;i++)
        {
            if(isVowel(s[i]))
                count+=1;
        }
        
        int maxi=count;
        for(int i=k;i<s.size();i++)
        {
            if(isVowel(s[i-k]))
                count-=1;
            
            if(isVowel(s[i]))
                count+=1;
            maxi=max(maxi,count);
        }
        
        return maxi;
        
    }
};