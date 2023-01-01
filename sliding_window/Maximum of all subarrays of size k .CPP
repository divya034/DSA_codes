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
