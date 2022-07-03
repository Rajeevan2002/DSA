if(numRows==1)
            return s;
        
        string res="";
        for(int r=0;r<numRows;r++)
        {
            int incr=2*(numRows-1);
            for(int i=r;i<s.size();i+=incr)
            {
                res+=s[i];
                if(r>0 && r<numRows-1 && i+incr-2*r<s.size())
                    res+=s[i+incr-2*r];
            }
        }
        
        return res;