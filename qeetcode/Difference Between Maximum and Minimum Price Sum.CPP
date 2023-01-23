class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> tree(n); 
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]); 
            tree[e[1]].push_back(e[0]); 
        }
        long long ans = 0; 
        
        function<pair<long, long>(int, int)> dfs = [&](int u, int p) {
            vector<pair<long, int>> leaf, noleaf; 
            for (auto& v : tree[u]) {
                if (v != p) {
                    auto [lf, no] = dfs(v, u); 
                    leaf.emplace_back(lf+price[u], v); 
                    noleaf.emplace_back(no+price[u], v); 
                }
            }
            if (leaf.size() == 0) {
                leaf.emplace_back(price[u], u); 
                noleaf.emplace_back(0, u); 
            }
            if (leaf.size() == 1) {
                long long cand1 = leaf[0].first - price[u], cand2 = noleaf[0].first; 
                ans = max({ans, cand1, cand2}); 
            } else {
                sort(leaf.begin(), leaf.end(), greater<>()); 
                sort(noleaf.begin(), noleaf.end(), greater<>()); 
                long long cand = 0; 
                if (leaf[0].second != noleaf[0].second) cand = leaf[0].first + noleaf[0].first - price[u]; 
                else cand = max(leaf[0].first + noleaf[1].first, leaf[1].first + noleaf[0].first) - price[u]; 
                ans = max(ans, cand); 
            }
            return make_pair(leaf[0].first, noleaf[0].first); 
        }; 
        
        dfs(0, -1); 
        return ans; 
    }
};
