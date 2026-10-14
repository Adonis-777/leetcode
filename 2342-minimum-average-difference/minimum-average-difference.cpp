
class Solution {
public:

    typedef long long ll;
    int minimumAverageDifference(vector<int>& nums) {

        int n = nums.size();
        ll total = 0;

        for(int x : nums)
            total += x;

        ll sum = 0, avg = LLONG_MAX;
        int index = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            ll left = sum / (i + 1);
            ll rightSum = total - sum;

            ll right = (i == n - 1) ? 0 : rightSum / (n - i - 1);
            ll diff = abs(left - right);

            if(diff < avg) {
                avg = diff;
                index = i;
            }
        }

        return index;
    }
};
