class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ans = 0; 
        for (auto& x : nums) {
            ans +=x ; 
            while (x) {
                ans -= x % 10; 
                x/= 10;
            }
        }
        return ans; 
    }
};
