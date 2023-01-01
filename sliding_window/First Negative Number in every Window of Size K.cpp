vector<long long> printFirstNegativeInteger(long long int A[] , long long int N, long long int K) {
    int start=0,end=0;
    //ans = list
    //res = final ans
    deque<long long> ans;
    vector<long long> res;
    while(end < N){
        if(A[end] < 0){
            ans.push_back(A[end]);
        }
        if(end-start+1 < K){
            end++;
        }
        else if(end-start+1 == K){
            if(ans.size()==0){
                res.push_back(0);
            }
            else{
                res.push_back(ans.front());
                if(A[start]<0)
                    ans.pop_front();
            }
            start++;
            end++;
        }
    }
    return res;
}
