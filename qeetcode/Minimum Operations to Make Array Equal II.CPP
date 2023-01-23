class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) {
            for (int i = 0; i < nums1.size(); ++i) 
                if (nums1[i] != nums2[i]) return -1; 
            return 0; 
        }
        long long ans = 0, diff = 0; 
        for (int i = 0; i < nums1.size(); ++i) {
            int val = nums1[i] - nums2[i]; 
            if (val % k) return -1; 
            ans += abs(val)/k; 
            diff += val; 
        }
        return diff == 0 ? ans / 2 : -1; 
    }
};


class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0, diff = 0; 
        for (int i = 0; i < nums1.size(); ++i) {
            int val = nums1[i] - nums2[i]; 
            if (k == 0 && val || k && val % k) return -1; 
            if (k) ans += abs(val)/k; 
            diff += val; 
        }
        return diff == 0 ? ans / 2 : -1; 
    }
};
