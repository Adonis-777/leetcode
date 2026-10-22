class Solution {
public:
    bool check(vector<int>& nums, int k, int val) {
        int n = nums.size();

        if(val < nums[0])
            return k <= val;

        if(val >= nums[n - 1])
            return (val - n) >= k;

        int pos = 0;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] > val) {
                pos = i + 1;
                break;
            }
        }

        return val - pos >= k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int l = 1, h = 1e7;
        int ans = -1;

        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(check(arr, k, mid)) {
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};