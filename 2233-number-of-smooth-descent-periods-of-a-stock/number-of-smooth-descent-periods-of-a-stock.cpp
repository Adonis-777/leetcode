class Solution {
public:

    typedef long long ll;
    long long getDescentPeriods(vector<int>& prices) {

        int n = prices.size();
        ll count = (ll)n;
        int i = 0, j = 0;

        while(j < n){
            while((i + 1) < n && (prices[i] - prices[i + 1] == 1)){
                i++;
            }
            ll len = (ll)i - (ll)j + 1;
            ll k = len * (len + 1) / 2;

            count += (k - len);
            i++;
            j = i;
        }

        return count;
        
    }
};