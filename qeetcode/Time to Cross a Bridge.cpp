class Solution {
public:
     int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> l0, r0;
        priority_queue<pair<int, int>> l1, r1;
        for (int i = 0; i < time.size(); ++i)
            l1.emplace(time[i][0]+time[i][2], i);
        int avail = 0; 
        while (n || !r0.empty() || !r1.empty()) {
            if (r1.empty() && (r0.empty() || r0.top().first>avail) && (!n || l1.empty() && (l0.empty() || l0.top().first>avail))) {
                int cand = INT_MAX;
                if (n && !l0.empty()) cand = min(cand, l0.top().first);
                if (!r0.empty()) cand = min(cand, r0.top().first);
                avail = cand;
            }
            while (!l0.empty() && l0.top().first <= avail) {
                auto [v, i] = l0.top(); l0.pop();
                l1.emplace(time[i][0]+time[i][2], i);
            }
            while (!r0.empty() && r0.top().first <= avail) {
                auto [v, i] = r0.top(); r0.pop();
                r1.emplace(time[i][0]+time[i][2], i);
            }
            if (!r1.empty()) {
                auto [v, i] = r1.top(); r1.pop();
                avail += time[i][2];
                if (n) l0.emplace(avail+time[i][3], i);
                else ans = max(ans, avail);
            } else {
                auto [v, i] = l1.top(); l1.pop();
                avail += time[i][0];
                r0.emplace(avail+time[i][1], i);
                --n;
            }
        }
        return ans;
    }
};
