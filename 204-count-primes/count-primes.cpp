class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n+1 , 1);
      
        for(int i =2 ; i <= n  ;i++){
            if(primes[i] == 0)continue;
            else{
                for(int   j = i*2 ; j <= n ;j+=i){
                   primes[j]  = 0;
                }

            }

        }
    int cnt =0;
    for(int i = 2 ; i  < n ; i++){
         if(primes[i] == 1)cnt++;
    }
return cnt;


    }
};