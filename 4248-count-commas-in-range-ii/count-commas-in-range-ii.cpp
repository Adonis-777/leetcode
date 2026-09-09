class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        if(n < 1000) return 0;

        if(n < 1e6){
            return ((n - 1e3) + 1);
        }

        if(n < 1e9){
            ll temp = ((1e6 - 1) - 1e3) + 1;
            temp += (ll)(((n - 1e6) + 1) * 2);
            //return (((n - 1e6) + 1) * 2);
            return temp;
        }

        if(n < 1e12){

            //ie9 - 1 - 1e6 + 1 * 2
            //1e6 - 1 - 1e3 + 1

            ll temp = (ll)(((1e6 - 1) - 1e3) + 1) + ((((1e9 - 1) - 1e6) + 1) * 2) + (((n - 1e9) + 1) * 3);
            
            return temp;
        }

        if(n < 1e15){
            ll temp = (ll)(((1e6 - 1) - 1e3) + 1) + ((((1e9 - 1) - 1e6) + 1) * 2) + ((((1e12 - 1) - 1e9) + 1) * 3) + (((n - 1e12) + 1) * 4);
            return temp;
        }

        ll temp = (ll)(((1e6 - 1) - 1e3) + 1) + ((((1e9 - 1) - 1e6) + 1) * 2) + ((((1e12 - 1) - 1e9) + 1) * 3) + ((((1e15 - 1) - 1e12) + 1) * 4) + (((n - 1e15) + 1) * 5);

        return temp;
    }
};