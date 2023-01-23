class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0; 
        unordered_map<int, int> freq; 
        long long total = 0; 
        int ii = 0; 
        for (auto& x : nums) {
            total += freq[x]; 
            ++freq[x]; 
            while (total >= k) {
                --freq[nums[ii]]; 
                total -= freq[nums[ii]]; 
                ++ii; 
            }
            ans += ii; 
        }
        return ans; 
    }
};
