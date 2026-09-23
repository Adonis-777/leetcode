class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
       

        ll total = 0;
        for(int t : nums)
            total += (ll)t;

        if(x == total)
            return n;
        
        ll target = (ll)total - x;
        // we want to get largest subarray with sum = target
        map<ll, int> mp;
        mp[0] = -1;
        ll sum = 0;
        int maxLen = -1;

        for(int i = 0; i < n; i++){
            sum += (ll)nums[i];

            if(sum == target){
                int len = i + 1;
                maxLen = max(maxLen, len);
            }

            ll comp = (ll)sum - target;
            if(mp.count(comp)){
                int len = i - mp[comp];
                maxLen = max(maxLen, len);
            }
            
            if(!mp.count(sum)){
                mp[sum] = i;
            }
        }

        if(maxLen == -1)
            return -1;
        return (n - maxLen);

        
    }
};