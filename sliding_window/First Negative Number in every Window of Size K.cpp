vector<long long> printFirstNegativeInteger(long long int A[] , long long int N, long long int K) {
    int start=0,end=0;
    //ans = list
    //res = final ans
    deque<long long> ans;
    vector<long long> res;
    while(end < N){
        if(A[end] < 0){ //CALCULATION 1
            ans.push_back(A[end]);
        }
        if(end-start+1 < K){
            end++;
        }
        else if(end-start+1 == K){
            if(ans.size()==0){ //ANSWER CALCULATION PART 1:  IF THERE IS NO -VE NUMBER IN THAT WINDOW
                res.push_back(0);
            }
            else{
                res.push_back(ans.front()); //ANSWER CALCULATION PART 2: THE FRONT WILL HAVE THE -VE NO. THAT APPEARED FIRST
                if(A[start]<0)   //REVERSE CALCULATION 1
                    ans.pop_front();
            }
            start++;
            end++;
        }
    }
    return res;
}
