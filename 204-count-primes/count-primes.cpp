class Solution {
public:

    typedef long long ll;
    int countPrimes(int n) {

        // sieve of eratosthenes
        vector<bool> sieve(n + 1, true);
        int count = 0;

        for(ll i = 2; i <= n; i++){

            if(sieve[i]){

                for(ll j = (i * i); j <= n; j = j + i){
                    sieve[j] = false;
                }
            }
        }

        for(int i = 2; i < n; i++){
            if(sieve[i])
                count++;
        }

        return count;

        
    }
};