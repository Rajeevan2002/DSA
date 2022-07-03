class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransom(26,0);
        for(int i=0;i<ransomNote.size();i++)
        {
            ransom[ransomNote[i]-'a']++;
        }
        
        for(int i=0;i<magazine.size();i++)
        {
            ransom[magazine[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            if(ransom[i]>0)
                return false;
        }
        return true;
    }
};