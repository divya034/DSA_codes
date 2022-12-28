class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long lo = 0, hi = 2e15, l = lcm((long) divisor1, divisor2); 
        while (lo < hi) {
            long mid = lo + (hi - lo)/2, extra = mid/l; 
            long cnt1 = mid - mid/divisor1, cnt2 = mid - mid/divisor2, cnt12 = mid - mid/divisor1 - mid/divisor2 + mid/l; 
            if (mid - mid/l >= uniqueCnt1 + uniqueCnt2 && cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && max(0l, uniqueCnt1-cnt1+cnt12)+max(0l, uniqueCnt2-cnt2+cnt12) <= cnt12) hi = mid; 
            else lo = mid + 1;
        }
        return lo; 
    }
};
