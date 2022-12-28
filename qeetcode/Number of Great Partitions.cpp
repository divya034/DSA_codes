class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9+7; 
        int n = nums.size(); 
        vector<vector<long>> ks01(n+1, vector<long>(k+1)); 
        ks01[n][0] = 1; 
        for (int i = n-1; i >= 0; --i) {
            ks01[i][0] = 2*ks01[i+1][0] % mod; 
            for (int j = 1; j <= k; ++j) {
                ks01[i][j] = (ks01[i+1][j] + ks01[i+1][max(0, j-nums[i])]) % mod; 
            }
        }
        vector<long> prefix(1); 
        for (auto& x : nums) prefix.push_back(prefix.back()+x); 
        vector<vector<long>> dp(n+1, vector<long>(k+1)); 
        for (int i = n-1; i >= 0; --i) {
            for (int j = k; j >= k-prefix[i] && j >= 0; --j) {
                if (j-nums[i] > 0) dp[i][j] = (dp[i+1][j] + dp[i+1][j-nums[i]]) % mod; 
                else dp[i][j] = (dp[i+1][j] + ks01[i+1][max(0l, 2*k-j-prefix[i])]) % mod; 
            }
        }
        return dp[0][k]; 
    }
};
