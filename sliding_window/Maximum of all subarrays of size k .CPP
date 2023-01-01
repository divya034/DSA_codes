For those who are getting wrong answers in some test cases: use deque instead of queue | C++
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int>q;
        int i=0,j=0;
        vector<int>res;
        while(j<n){
            while(!q.empty() && q.back()<arr[j]) 
              q.pop_back();
          
            q.push_back(arr[j]);
          
            if(j-i+1<k) 
              j++;
          
            else if(j-i+1==k){
                res.push_back(q.front());
                if(q.front()==arr[i]) 
                  q.pop_front();
                i++;
                j++;
            }
        }
        return res;
    }
};


because deque is doubly linked list ..
  . We can pop nd push from both side ... So for moving 
  into the next window we have to pop the element from front and have to push the element from back.
    
    
    //with comments
vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
    
        deque<int>q;// WILL HAVE MAX ELEMENT AT FRONT AND WILL HAVE only the window elements or less in list
        int i=0,j=0;
        vector<int>res; 
        while(j<n){
            while(!q.empty() && q.back()<arr[j]) //if the candidate that we thought can be max - failed (new arr[j] is > back)
              q.pop_back();
          
            q.push_back(arr[j]);
          
            if(j-i+1<k) 
              j++;
          
            else if(j-i+1==k){
                res.push_back(q.front());
                if(q.front()==arr[i]) // if arr[i] that is the start of window... is the max element(front of q) ??
                  q.pop_front(); //remove the max element from list as its not in window anymore
                //else we dont need to remove anything 
              //because the front(max ele) that will go in res will always be in window(should be present in list)
                i++;
                j++;
            }
        }
        return res;
    }
