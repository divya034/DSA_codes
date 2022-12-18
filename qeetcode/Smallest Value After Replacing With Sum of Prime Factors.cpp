class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int cand = 0; 
            for (int p = 2, nn = n; p <= nn; ++p) 
                for (; nn % p == 0; nn /= p)
                    cand += p; 
            if (cand == n) break; 
            n = cand; 
        }
        return n; 
    }
};
