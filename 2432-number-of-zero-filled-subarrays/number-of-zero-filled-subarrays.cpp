class Solution {
public:

    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {

        int n = nums.size();
        ll prev = 0, count = 0;

        vector<ll> pre(n + 1, 0);
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + (ll)i;
        }

        for(int i = 0; i < n; i++){

            if(nums[i] == 0){
                prev++;
            } else {

                count += pre[prev];
                prev = 0;
            }
        }

        if (prev != 0) {
            count += pre[prev];
        }
        
        return count;
    }
};