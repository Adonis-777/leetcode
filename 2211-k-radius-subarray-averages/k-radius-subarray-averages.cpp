
class Solution {
public:
    typedef long long ll;

    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(2LL * k + 1 > n)
            return vector<int>(n, -1);

        vector<int> ans(n, -1);

        int len = 2*k + 1;
        int j = 0, i;
        ll sum = 0;  // changed int to ll

        for(i = 0; i <= 2*k; i++){
            sum += nums[i];
        }

        int curr = k;
        while(curr < (n - k)){

            ans[curr] = sum / len;
            sum -= nums[j++];

            if(i < n)
                sum += nums[i++];

            curr++;
        }
    
        return ans;
    }
};
