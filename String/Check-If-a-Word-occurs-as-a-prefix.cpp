class Solution {
public:
    void fillLps(string str,vector<int> &lps)
    {
        int i=1;
        int len=0;
        int n=str.size();
        while(i<n)
        {
            if(str[i]==str[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                {
                    len=lps[len-1];
                }       
            }
        }
    }
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        vector<int> lps(searchWord.size(),0);
        fillLps(searchWord,lps);
        string pat=searchWord;
        
        int i=0;
        int len=0;
        vector<string> words;
        string simp="";
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' ')
            {
                words.push_back(simp);
                simp="";
            }
            else
            {
                simp+=sentence[i];
            }
        }
        words.push_back(simp);
        
        for(int k=0;k<words.size();k++)
        {
            int i=0;
            int j=0;
            int n=words[k].size();
            string text=words[k];
            // cout<<words[k]<<endl;
            while(i<n)
            {
                if(pat[j]==text[i])
                {
                    i++;
                    j++;
                }
                if(j==pat.size())
                {
		    if(i-j==0)
	                    return k+1;
                    j=lps[j-1];
                }
                else if(i<n && pat[j]!=text[i])
                {
                    if(j==0)
                        i++;
                    else
                        j=lps[j-1];
                }
            }
        }
        return -1;
        
        
    }
};