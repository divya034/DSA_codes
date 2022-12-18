Smallest Value After Replacing With Sum of Prime Factors
class Solution {
public:
    int smallestValue(int n) {
//nn= new n;
//p = prime factor
//cand = sum of pfs
       while (true) {
            int cand = 0; 
            for (int p = 2, nn = n; p <= nn; ++p) //notice: p <= new n not n 
                for (nn = nn; nn % p == 0; nn /= p)
                    cand += p; 
            if (cand == n) break; 
            n = cand; 
        }
        return n; 
    }
};

MY SOLUTION:
class Solution {
public:
    int smallestValue(int n) {
       while(true){ 
        int present_sum = 0;
         int present_n = n;
        for(int prime_factor = 2 ; prime_factor< n; prime_factor++){
            for(; present_n % prime_factor == 0; present_n = present_n/ prime_factor){ // IF PF DIVIDES N AGAIN
                present_sum = present_sum + prime_factor;
                // break; (if we need to take each prime factor once)
            }
             //PROBLEM: N WILL BECOME DIVIDED BY PF IF PF EXISTS
           //checked with one prime factor

        } 
        // checked with all prime factors
        
        if(present_sum == 0) // if no factors
           break;
        if(present_sum == n) // if we get the same sum OF ALL PFS as the original number like for N = 3,4 we break
           break;
        n = present_sum; // now check repeat for the sum of prime factors
        
       }
        return n;
    }
};
