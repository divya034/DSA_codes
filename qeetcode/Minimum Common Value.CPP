class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0, ii = 0; i < nums1.size() && ii < nums2.size(); ) {
            if (nums1[i] < nums2[ii]) ++i; 
            else if (nums1[i] == nums2[ii]) return nums1[i]; 
            else ++ii; 
        }
        return -1; 
    }
};
