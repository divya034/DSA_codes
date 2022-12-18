class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        map<set<char> , int> mp;
        for(auto s:words){ // loop in the words
            set<char> st;
            for(char c:s) // loop in each word for each character
              st.insert(c); // add these characters in the set
            
            mp[st]++; // increase the count of that particular combination of SET with chars
        }
        int res=0;
        for(auto p:mp){   // loop through the Map
            if(p.second>1){ // if a combination comes more than once
                int n=p.second;
                res = res + (n*(n-1))/2;
            }
        }
        return res;

    }
};
