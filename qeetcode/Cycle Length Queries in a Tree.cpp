class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans; 
        for (auto& q : queries) {
            int a = q[0], b = q[1]; 
            unordered_map<int, int> dist; 
            for (dist[a] = 1; a/2; a /= 2) 
                dist[a/2] = 1 + dist[a]; 
            for (int d = 0; b; b /= 2, ++d) {
                if (dist.count(b)) {
                    ans.push_back(d + dist[b]); 
                    break; 
                }
            }
        }
        return ans; 
    }
};
