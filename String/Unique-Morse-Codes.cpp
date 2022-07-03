class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string> mp={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<string,int> ump;
        for(auto x:words)
        {
            string temp="";
            for(auto y:x)
                temp+=mp[y-'a'];
            ump[temp]+=1;
        }
        
        return ump.size();
        
    }
};