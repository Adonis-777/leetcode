class Solution {
public:

    typedef long long ll;
    int countPairs(vector<int>& deliciousness) {

        int n = deliciousness.size();
        if(n < 2){
            return 0;
        }
        


        ll MOD = 1000000007;
        map<int, ll> mp;

        int ans = 0;
        for(int x : deliciousness){

            for(int i = 0; i <= 21; i++){

                ll power = 1 << i;
                ll needed = power - (ll)x;

                ans = (ans + mp[needed]) % MOD;
            }

            mp[x]++;
        }

        return ans;

        
    }
};