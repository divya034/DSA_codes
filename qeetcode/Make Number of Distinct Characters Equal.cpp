class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> f1, f2; 
        for (auto& ch : word1) ++f1[ch]; 
        for (auto& ch : word2) ++f2[ch]; 
        for (auto& c1 : string("abcdefghijklmnopqrstuvwxyz")) {
            for (auto& c2 : string("abcdefghijklmnopqrstuvwxyz")) {
                if (f1.count(c1) && f2.count(c2)) {
                    if (--f1[c1] == 0) f1.erase(c1); 
                    ++f1[c2]; 
                    if (--f2[c2] == 0) f2.erase(c2); 
                    ++f2[c1]; 
                    if (f1.size() == f2.size()) return true; 
                    ++f1[c1]; 
                    if (--f1[c2] == 0) f1.erase(c2); 
                    ++f2[c2]; 
                    if (--f2[c1] == 0) f2.erase(c1); 
                }
            }
        }
        return false; 
    }
};


class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> f1(26), f2(26); 
        for (auto& ch : word1) ++f1[ch-'a']; 
        for (auto& ch : word2) ++f2[ch-'a']; 
        for (auto& c1 : string("abcdefghijklmnopqrstuvwxyz")) 
            for (auto& c2 : string("abcdefghijklmnopqrstuvwxyz")) 
                if (f1[c1-'a'] && f2[c2-'a']) {
                    --f1[c1-'a']; ++f1[c2-'a']; 
                    --f2[c2-'a']; ++f2[c1-'a']; 
                    int diff = 0; 
                    for (int i = 0; i < 26; ++i) {
                        if (f1[i]) ++diff; 
                        if (f2[i]) --diff; 
                    }
                    if (diff == 0) return true; 
                    ++f1[c1-'a']; --f1[c2-'a']; 
                    ++f2[c2-'a']; --f2[c1-'a']; 
                }
        return false; 
    }
};
