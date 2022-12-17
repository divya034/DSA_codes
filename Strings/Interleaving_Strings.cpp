class Solution {
private:
    bool isInterleave_helper(string s1,string s2, string s3, int i, int j, int k, vector<vector<int>> &m){
        if(m[i][j] != -1){
            return m[i][j];
        }
        
        if(s1.length() == i && s2.length() == j && s3.length() == k){
            return true;
        }
       bool x=0, y = 0; // automatically zero in every call
        if(i< s1.length() && s1[i] == s3[k]){
             x = isInterleave_helper(s1, s2, s3, i+1, j, k+1, m); 
        }

        if(j< s2.length() && s2[j] == s3[k]){
             y = isInterleave_helper(s1, s2, s3, i, j+1, k+1, m); 
        }
  //for example i = 3 and j = 2  (3,2,5) comes true, save 1. 
  //else if value is false (5,3,8) save 0, as s3[8] doesnt match i or j chars
    
    return m[i][j] = x || y;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.length(),b=s2.length();
        vector<vector<int>> m(a+1,vector<int>(b+1,-1));
        int i=0,j=0,k=0;
        return isInterleave_helper(s1, s2, s3, 0, 0, 0, m); 
    }
};
