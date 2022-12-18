class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words; 
        istringstream iss(sentence); 
        string word; 
        while (iss >> word) words.push_back(word); 
        for (int i = 0, n = words.size(); i < n; ++i) 
            if (words[i].back() != words[(i+1) % n][0]) return false; 
        return true; 
    }
};
