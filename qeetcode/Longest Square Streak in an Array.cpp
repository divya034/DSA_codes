class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<int> dp(100'001); 
        for(auto& x : nums) dp[x] = 1; 
        int ans = 0; 
        for (auto& x : nums) {
            int r = sqrt(x); 
            if (r * r == x) dp[x] = 1 + dp[r]; 
            ans = max(ans, dp[x]); 
        }
        return ans > 1 ? ans : -1; 
    }
};
