class Solution {
public:
    typedef long long ll;
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {

        // (curr - prev) % mod == k 
        // --> (curr % mod - k + mod) % mod = prev % mod

        int n = nums.size();
        int curr = 0;
        ll count = 0;

        map<int, ll> mp;
        mp[0]++;

        for(int x : nums){

            if(x % mod == k){
                curr++;
            }

            int comp = (curr % mod - k + mod) % mod;
            if(mp.count(comp)){
                count += mp[comp];
            }

            mp[curr % mod]++;
        }

        return count;
        
    }
};