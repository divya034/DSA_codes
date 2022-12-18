class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(), total = accumulate(skill.begin(), skill.end(), 0); 
        if (2*total % n == 0) {
            int target = 2*total / n; 
            long long ans = 0; 
            unordered_map<int, int> freq; 
            for (auto& x : skill) ++freq[x]; 
            for (auto& [k, v] : freq) {
                if (v != freq[target - k]) return -1; 
                ans += (long long) k * (target-k) * v; 
            }
            return ans/2; 
        }
        return -1; 
    }
};
