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
                int n=p.second;  // how many times the combination comes
                res = res + (n*(n-1))/2; // ans + number of pair that can be formed with N
            }
        }
        return res;

    }
};


//for looping over the map:
["aba","aabb","abcd","bac","aabc"] ans = 2

 for(auto p:mp){
            //cout<<p.first wont work as p.first is a string
            for(auto c:p.first) 
               cout<<c;
            cout<<" ";
            cout<<p.second<<endl;
        }
        
Stdout
ab 2
abc 2
abcd 1
    
   unordered_map<set<char> , int> mp; THIS WONT WORK ERROR CANT PASS SET IN UNORDERED MAP. CHECK GEEKFOR GEEKS
Unordered Map does not contain a hash function for a pair like it has for int, string, etc,
So if we want to hash a pair then we have to explicitly provide it with a hash function that can hash a pair.
    unordered_map can takes upto 5 arguments: 
 

Key : Type of key values
Value : Type of value to be stored against the key
Hash Function : A function which is used to hash the given key. If not provided it uses default hash function.
Pred : A function which is used so that no two keys can have same hash values
Alloc : An object used to define the memory model for the map
