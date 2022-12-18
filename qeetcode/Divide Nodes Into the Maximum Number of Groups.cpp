class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); 
        for (auto& e : edges) {
            graph[e[0]-1].push_back(e[1]-1); 
            graph[e[1]-1].push_back(e[0]-1); 
        }
        vector<int> seen(n); 
        vector<vector<int>> parts; 
        for (int x = 0; x < n; ++x) {
            if (!seen[x]) {
                seen[x] = 1; 
                stack<int> stk; stk.push(x); 
                vector<int> part = {x}; 
                while (stk.size()) {
                    auto u = stk.top(); stk.pop(); 
                    for (auto& v : graph[u]) {
                        if (!seen[v]) {
                            seen[v] = seen[u] + 1; 
                            stk.push(v);
                            part.push_back(v); 
                        } else if ((seen[u]&1) == (seen[v]&1)) return -1; 
                    }
                }
                parts.push_back(part); 
            }
        }
        
        auto bfs = [&](int x) {
            int ans = 0; 
            vector<bool> seen(n); seen[x] = true; 
            queue<int> q; q.push(x); 
            while (q.size()) {
                for (int sz = q.size(); sz; --sz) {
                    auto u = q.front(); q.pop(); 
                    for (auto& v : graph[u]) {
                        if (!seen[v]) {
                            seen[v] = true; 
                            q.push(v); 
                        }
                    }
                }
                ++ans; 
            }
            return ans; 
        }; 
        
        int ans = 0; 
        for (auto& part : parts) {
            int cand = 0; 
            for (auto& x : part) cand = max(cand, bfs(x)); 
            ans += cand; 
        }
        return ans; 
    }
};
