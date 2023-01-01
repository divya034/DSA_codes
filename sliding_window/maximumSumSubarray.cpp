class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &v , int n){
        long ans=-1;
        int start =0;
        int end =0;
        long sum=0;
        while (end<n){
            sum+=v[end];
            if ((end- start + 1)<k){
                end++;
                continue;
            }
            else if((end - start + 1)==k){
                ans = max(ans,sum);
                sum -= v[start];
                // cout<<"sum"<<sum<<endl;
                start++;
                end++;
            }
        }
        return ans;
    }
