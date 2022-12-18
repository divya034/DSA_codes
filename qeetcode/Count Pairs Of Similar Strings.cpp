class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0; 
        unordered_map<int, int> freq; 
        for (auto& word : words) {
            int mask = 0; 
            for (auto& ch : word) 
                mask |= 1<<ch-'a'; 
            ans += freq[mask]++;
        }
        return ans; 
    }
};
