class Solution {
public:
    int dp[102][102];
	
	// to give count of minimal changes to make this string from i to j palindrome
    int palindrome(string &s, int i, int j){
        int cnt = 0;
        while(i<j){
		
			// if not same, changing one character will work
            if(s[i]!=s[j]) cnt++;
            i++, j--;
        }
        return cnt;
    }
    int solve(int i, string &s, int k){
	
		// if i reaches end and k equals zero then return 0 (Indicates that task done) else return big number to indicate task not done here, 1e3 (1000) because maximum changes is 100
        if(i==s.length()){
            if(k==0) return 0;
            else 10e3;
        }
		
		// at any point k equals zero then task not done
        if(k==0) return 1e3;
        
		// find if at position i with k div possible available for not.
        if(dp[i][k]!=-1) return dp[i][k];
        
		
        int minChanges = 1e3;
        for(int cut = i+1; cut<=s.length(); cut++){
            int changes = palindrome(s, i, cut-1);
            // taking minimum of all combination
			minChanges = min(minChanges, changes + solve(cut, s, k-1));
        }
        return dp[i][k] = minChanges;
    }
    int palindromePartition(string s, int k) {
        memset(dp, -1, sizeof dp);
        return solve(0, s, k);
    }
};
