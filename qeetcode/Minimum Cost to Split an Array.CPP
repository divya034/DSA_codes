class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> dp(n+1, INT_MAX); 
        dp.back() = 0; 
        for (int i = n-1; i >= 0; --i) {
            int sum = 0; 
            vector<int> freq(n); 
            for (int j = i; j < n; ++j) {
                int cnt = ++freq[nums[j]]; 
                if (cnt == 2) sum += 2; 
                else if (cnt > 2) ++sum; 
                dp[i] = min(dp[i], k + sum + dp[j+1]); 
            }
        }
        return dp[0]; 
    }
};
