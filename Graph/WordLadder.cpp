class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(s.find(endWord)==s.end())
            return 0;
        
        int ans=1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            int sizze=q.size();
            ans+=1;
            for(int i=0;i<sizze;i++)
            {
                string word=q.front();
                q.pop();
                
                for(int j=0;j<word.size();j++)
                {
                    string temp=word;
                    for(char ch='a';ch<='z';++ch)
                    {
                        temp[j]=ch;
                        if(temp==endWord)
                            return ans;
                        else if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                        else if(temp==word)
                        {
                            continue;                        
                        }
                    }
                    
                }
            }
            
        }
        return 0;
        
    }
};