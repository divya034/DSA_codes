class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n); 
        for (auto& e : edges) {
            graph[e[0]-1].insert(e[1]-1); 
            graph[e[1]-1].insert(e[0]-1);
        }
        vector<int> nodes; 
        for (int u = 0; u < n; ++u)
            if (graph[u].size() & 1) nodes.push_back(u); 
        if (nodes.size() == 0) return true; 
        if (nodes.size() == 2) {
            for (auto& g : graph) 
                if (!g.count(nodes[0]) && !g.count(nodes[1])) return true; // if these 2 nodes with negative degree are not connected then true
            return false; 
        }
        if (nodes.size() == 4) {
            int a = nodes[0], b = nodes[1], c = nodes[2], d = nodes[3]; 
            if (!graph[a].count(b) && !graph[c].count(d) || !graph[a].count(c) && !graph[b].count(d) || !graph[a].count(d) && !graph[b].count(c)) return true; 
            return false; 
        }
        return false; 
    } 
};
