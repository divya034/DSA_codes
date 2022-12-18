Maximum Value of a String in an Array

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0; 
        for (auto& word : strs) {
            bool found = false; 
            for (auto& ch : word) {
                if ('a' <= ch && ch <= 'z') { found = true; break; }
            }
            int cand = found ? (int) word.size() : stoi(word); 
            ans = max(ans, cand); 
        }
        return ans; 
    }
};
