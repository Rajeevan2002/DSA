class Solution {
public:
    int numo(char ch)
    {
        switch(ch)
        {
            case 'I': return 1;
                      break;
            case 'V': return 5;
                      break;
            case 'X': return 10;
                      break;
            case 'L': return 50;
                      break;
            case 'C': return 100;
                      break;
            case 'D': return 500;
                      break;
            case 'M': return 1000;
                      break;
                
        }
        return -1;
    }
    int romanToInt(string s) 
    {
        int res=0;
        int i=0;
        int n=s.size();
        while(i<n)
        {
            if(s[i]=='I' && i+1<n && s[i+1]!='I' && (s[i+1]=='V' || s[i+1]=='X'))
            {
                if(s[i+1]=='X')
                    res+=9;
                else if(s[i+1]=='V')
                    res+=4;
                i+=2;
                continue;
            }
            
            if(s[i]=='X' && i+1<n && s[i+1]!='X' && (s[i+1]=='L' || s[i+1]=='C'))
            {
                if(s[i+1]=='L')
                    res+=40;
                else if(s[i+1]=='C')
                    res+=90;
                i+=2;
                continue;
            }
            
            if(s[i]=='C' && i+1<n && s[i+1]!='C' && (s[i+1]=='D' || s[i+1]=='M'))
            {
                if(s[i+1]=='D')
                    res+=400;
                else if(s[i+1]=='M')
                    res+=900;
                i+=2;
                continue;
            }
            
            res+=numo(s[i]);
            i+=1;
        }
        
        return res;
    }
};