class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end()); 
        int n = price.size(); 
        int lo = 0, hi = price[n-1] - price[0]; 
        while (lo < hi) {
            int mid = lo + (hi - lo+1)/2; 
            int pp = price[0], kk = 0; 
            for (auto& p : price) {
                if (p >= pp + mid) {
                    ++kk; 
                    pp = p; 
                }
            }
            if (kk >= k-1) lo = mid; 
            else hi = mid-1; 
        } 
        return lo; 
    }
};
