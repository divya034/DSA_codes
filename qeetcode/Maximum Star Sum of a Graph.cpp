class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size(); 
        vector<vector<int>> graph(n); 
        for (auto& e : edges) {
            int u = e[0], v = e[1]; 
            graph[u].push_back(v); 
            graph[v].push_back(u); 
        }
        int ans = INT_MIN; 
        for (int u = 0; u < n; ++u) {
            if (graph[u].size() > k) 
                nth_element(graph[u].begin(), graph[u].begin()+k, graph[u].end(), [&](auto& lhs, auto& rhs) {
                    return vals[lhs] > vals[rhs]; 
                }); 
            int cand = vals[u]; 
            for (int v = 0; v < k && v < graph[u].size(); ++v) 
                cand += max(0, vals[graph[u][v]]); 
            ans = max(ans, cand); 
        }
        return ans; 
    }
};
