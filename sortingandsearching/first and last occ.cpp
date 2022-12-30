class Solution {

   
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target) ;
       // cout<<**l<<" "<<**r; can't print an iterator but u can compare *r = target
       // we check l first because r is not the last occ yet , we didnt do -1
       //hence r cant be target yet
        if( l != nums.end() && *l == target){
            ans[0] = l-nums.begin();
            ans[1] = r-nums.begin()-1;
        }
        cout<< r-nums.begin();
      return ans;

    }
};
