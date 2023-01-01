LeetCode 438:

 vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>m;
        
        vector<int>v;
        
        for(int i=0;i<p.size();i++)m[p[i]]++;
        
        int count=m.size(),i=0,j=0,k=p.size();
        
        while(j<s.size()){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0)count--;
            }
            
            if(j-i+1<k) j++;
            
            else if(j-i+1==k){
                if(count==0)v.push_back(i);
                
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1)count++;
                }
                i++;
                j++;
            }
        }
        return v;
        
      }





int countOccurencesOfAnagrams(string str, string pattern) {
    int ans=0, k = pattern.size();
    unordered_map<char, int> map;
    //building the map
    for(auto i: pattern)
      map[i]++;
    // storing no of distinct/unique elements in map
    int countDistinct = map.size();
    //sliding window
    int ws=0;  //window start
    for(int we=ws; we<str.size(); we++) {
      // calculations/storing area
      if(map.count(str[we]) > 0) { //IF KEY PRESENT IN MAP, then only do the operations!
        map[str[we]]--;
        if(map[str[we]] == 0) 
          countDistinct--;
      }
  
      //window hit area
      if(we >= k-1) {
        if(countDistinct == 0) ans++; // ans
        // adjust calculations before shifting ws
        if(map.count(str[ws]) > 0) {
          map[str[ws]]++;
          if(map[str[ws]] == 1) 
            countDistinct++;
        }

        ws++; // shift
      }
    }
    return ans;
  }
  
  
  
  
  
  
  class Solution{
public:

	int search(string pat, string txt) {
	    
	    unordered_map<char, int> countMap;
	    int anagramCount = 0;


		// Stores thd distinct characters needed in total.
		// For eg for  3
		//        adaa 2
		//        yumu 3
	    int targetCountOfDistinctLetters;
	    
	    // Set the target map
	    for(auto&& i : pat)
	        countMap[i]++;
	    
		// How many numbers of distinct characters are there is size of map itslef.
	    targetCountOfDistinctLetters = countMap.size();
	    
	    // Get the first window.
	    for(int i = 0; i < pat.size(); i++){
	        if(countMap.find(txt[i])!=countMap.end())
	            countMap[txt[i]]--;
	    }
	    
	    // Set Counters
	    for(auto&& i : countMap){
	        if(i.second==0)  targetCountOfDistinctLetters--;
	    }
	        
	    if(targetCountOfDistinctLetters==0)   anagramCount++;     
	        
	    // Slide thew Window
	    for(int i = pat.size(); i < txt.size(); i++){
	        
	        if(countMap.find(txt[i])!=countMap.end()){
    	        countMap[txt[i]]--;

				// Previously was 0 but now disbalanced.
    	        if(countMap[txt[i]]+1 == 0) targetCountOfDistinctLetters++;
    	        
				// Just now reached 0.
				if(countMap[txt[i]] == 0) targetCountOfDistinctLetters--;
	        }
	        
	        if(countMap.find(txt[i-pat.size()])!=countMap.end()){
    	        countMap[txt[i-pat.size()]]++;

				// Previously was 0 but now disbalanced.
    	        if(countMap[txt[i-pat.size()]]-1 == 0) targetCountOfDistinctLetters++;

				// Just now reached 0.
    	        if(countMap[txt[i-pat.size()]] == 0) targetCountOfDistinctLetters--;
	        }
	        
			// If everything is balanced means its anagram so increase its count.
	        if(targetCountOfDistinctLetters==0)   anagramCount++;
	    }
	    
	    return anagramCount;
	    
	}

};
