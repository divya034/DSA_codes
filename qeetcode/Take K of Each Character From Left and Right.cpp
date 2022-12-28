class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> freq(3); 
        int ans = INT_MAX, n = s.size(), j = 0; 
        for (int i = 0; i < 2*n; ++i) {
            ++freq[s[i%n] - 'a']; 
            while (*min_element(freq.begin(), freq.end()) == k) {
                if (j <= n && i >= n-1 && i-j < n) ans = min(ans, i-j+1); 
                --freq[s[j%n]-'a']; 
                ++j; 
            }
        }
        return ans < INT_MAX ? ans : -1;
    }
};
