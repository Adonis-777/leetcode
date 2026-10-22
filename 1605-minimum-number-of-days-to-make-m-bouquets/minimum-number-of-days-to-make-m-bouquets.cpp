class Solution {
public:
    bool check(vector<int>& nums, int req_count, int windowSize, int limit) {
        int n = nums.size();
        int curr_count = 0;
        int consecutive = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] <= limit) {
                consecutive++;

                if(consecutive == windowSize) {
                    curr_count++;
                    consecutive = 0;
                }
            }
            else {
                consecutive = 0;
            }
        }

        return curr_count >= req_count;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long requirement = (long long)m * (long long)k;

        if(requirement > n)
            return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = h;

        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(check(bloomDay, m, k, mid)) {
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