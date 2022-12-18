class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        for (auto& row : grid) sort(row.begin(), row.end()); 
        int ans = 0; 
        for (int j = 0; j < n; ++j) {
            int cand = 0; 
            for (int i = 0; i < m; ++i) cand = max(cand, grid[i][j]); 
            ans += cand; 
        }
        return ans; 
    }
};
