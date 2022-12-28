class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX, n = words.size(); 
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int cand = abs(i - startIndex); 
                ans = min({ans, cand, n - cand}); 
            }
        }
        return ans < INT_MAX ? ans : -1; 
    }
};
