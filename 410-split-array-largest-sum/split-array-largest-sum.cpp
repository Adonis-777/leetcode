class Solution {
public:

    int kadane(vector<int>& nums) {

        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = max(sum, sum + nums[i]);
            ans = max(ans, sum);
        }

        return ans;
    }

    bool helper(vector<int>&nums, int allowed, int k) {

        int n = nums.size();
        int sum = 0, maxSum = 0;
        int required = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] > allowed)
                return false;

            sum = max(sum, sum + nums[i]);
            maxSum = max(maxSum, sum);

            if (maxSum > allowed) {
                i--;
                required++;
                sum = 0;
                maxSum = 0;
            }

            if (required > k)
                return false;
        }

        if (maxSum != 0)
            required++;

        return required <= k;

    }

    int splitArray(vector<int>& nums, int k) {

        int l = 0, r = kadane(nums);
        int ans;

        while (l <= r) {

            int mid = l + (r - l) / 2;
            if (helper(nums, mid, k)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;

    }
        

};