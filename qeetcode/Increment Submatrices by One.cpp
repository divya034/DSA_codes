class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n)); 
        for (auto& q : queries) {
            int i0 = q[0], j0 = q[1], i1 = q[2], j1 = q[3]; 
            ++ans[i0][j0]; 
            if (i1+1 < n) --ans[i1+1][j0]; 
            if (j1+1 < n) --ans[i0][j1+1];
            if (i1+1 < n && j1+1 < n) ++ans[i1+1][j1+1]; 
        }
        for (int i = 0; i < n; ++i) {
            int diff = 0; 
            for (int j = 0; j < n; ++j) {
                diff += ans[i][j]; 
                if (i) ans[i][j] = ans[i-1][j] + diff; 
                else ans[i][j] = diff; 
            }
        }
        return ans; 
    }
};
