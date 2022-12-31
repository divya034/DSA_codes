class Solution {
#LOGN
   
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

#My logn sol:
private:
    int firstOccur(vector<int> nums, int target){
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end-start)/2;
 
        while(start <= end){
           if(nums[mid] == target){
               ans =  mid;
               end = mid - 1;
           }
 
           else if(nums[mid] > target){
               end = mid - 1;
           }
 
           else{
               start = mid + 1;
           }
           
            mid = start + (end-start)/2;
        }
 
        return ans;
    }
 
    int secondOccur(vector<int> nums, int target){
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end-start)/2;
 
        while(start <= end){
           if(nums[mid] == target){
               ans =  mid;
               start = mid + 1;
           }
 
           else if(nums[mid] > target){
               end = mid - 1;
           }
 
           else{
               start = mid + 1;
           }
           
            mid = start + (end-start)/2;
        }
 
        return ans;
    }
 
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        ans[0] = firstOccur(nums, target);
        ans[1] = secondOccur(nums, target);
 
        return ans;
    }
