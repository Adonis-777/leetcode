
class Solution {
public:
    typedef long long ll;

    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());

        ll j = 0, count = 0;
        int freq = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == maxElement)
                freq++;

            while(freq >= k) {
                if(nums[j] == maxElement)
                    freq--;
                j++;
            }

            count += (i - j + 1);
        }

        ll total = (ll)n * (n + 1) / 2;
        return total - count;
    }
};
