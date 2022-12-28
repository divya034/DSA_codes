class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0, prev = 0; 
        for (int i = 0; i < forts.size(); ++i) {
            if (forts[i]) {
                if (forts[prev] == -forts[i]) ans = max(ans, i - prev - 1); 
                prev = i; 
            }
        }
        return ans; 
    }
};
