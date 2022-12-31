class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
  
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] > arr[mid+ 1]) 
               hi = mid;  
              
            else
               lo = mid + 1;

        
        return lo;  
    }
      
      
      //OOOORRRRRRRR
        
       int start = 0;
       int end = arr.size() - 1;
       int mid = start + (end - start)/2;

       while(start < end){
           //left and asc : small to big elementssssss
           if(arr[mid] < arr[mid + 1]){
               start = mid + 1;
           }

           //pivot and right hand side
           else{
               end = mid;
           }

            mid = start + (end - start)/2;

       }

       return start;
};
