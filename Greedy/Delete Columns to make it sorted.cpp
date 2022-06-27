class Solution {
public:
    int minDeletionSize(vector<string>& A) 
    {
        unordered_set<int> di;
        for (auto i = 1; i < A.size(); ++i) {
            for (auto j = 0; j < A[i].size(); ++j) {
                if (di.count(j) > 0 || A[i - 1][j] == A[i][j]) 
                    continue;
                if (A[i - 1][j] > A[i][j]) {
                    di.insert(j);
                    i = 0;
                }
                break;
            }
        }
        return di.size();
        
    }
};