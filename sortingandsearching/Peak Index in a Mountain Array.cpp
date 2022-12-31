class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int start = 0;
        int end = arr.size() - 1;
        int mid = (start) + (end-start)/2;
 
        while(start <= end){
              //arr length = 3 minimum
            if(mid-1>0 && arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            if(arr[mid] < arr[mid + 1]){
                start = mid + 1 ;
            }
            else{
                end = mid - 1;
            }
             mid = (start) + (end-start)/2;
        }
 
        return start;
    

      
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
        
    }
};
