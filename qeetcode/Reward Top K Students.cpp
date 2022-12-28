class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end()); 
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end()); 
        unordered_map<int, int> points; 
        for (int i = 0; i < report.size(); ++i) {
            istringstream iss(report[i]); 
            string word; 
            int val = 0; 
            while (iss >> word) {
                if (pos.count(word)) val += 3; 
                else if (neg.count(word)) --val; 
            }
            points[student_id[i]] = val; 
        }
        vector<int> ans; 
        for (auto& [id, _] : points) ans.push_back(id); 
        sort(ans.begin(), ans.end(), [&](auto& lhs, auto& rhs) {return points[lhs] > points[rhs] || points[lhs] == points[rhs] && lhs < rhs; }); 
             ans.resize(k); 
             return ans; 
    }
};
