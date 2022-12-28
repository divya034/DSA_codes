class Solution {
public:
    int countAnagrams(string s) {
        const int mod = 1e9+7; 
        int n = s.size(); 
        vector<long> fact(n+1, 1), ifact(n+1, 1), inv(n+1, 1); 
        for (int x = 1; x <= n; ++x) {
            if (x >= 2) inv[x] = mod - mod/x * inv[mod%x] % mod; 
            fact[x] = fact[x-1] * x % mod; 
            ifact[x] = ifact[x-1] * inv[x] % mod; 
        }
        long ans = 1; 
        istringstream iss(s); 
        string word; 
        while (iss >> word) {
            ans = ans * fact[word.size()] % mod; 
            unordered_map<char, int> freq; 
            for (auto& ch : word) ++freq[ch]; 
            for (auto& [_, v] : freq) ans = ans * ifact[v] % mod; 
        }
        return ans; 
    }
};
