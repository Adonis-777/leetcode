class Solution {
public:

    typedef long long ll;

    int twoPointer(vector<int>&nums, int size, int start, int end){

        int n = nums.size();
        int j = start;

        ll sum = 0, ans = 0;
        for(int i = start; i <= end; i++){

            sum += (ll)nums[i];
            while((i - j + 1) > size){
                sum -= nums[j++];
            }

            if((i - j + 1) == size){
                ans = (ans > sum) ? ans : sum;
            }
        }

        return (ans != 0) ? (int)ans : INT_MIN;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int sz1, int sz2) {
        
        int n = nums.size();
        int ans = INT_MIN;

        for(int i = 1; i < (n - 1); i++){

            // left: 0 --> i
            // right: (i + 1) --> (n - 1)

            // case1: left_sz1 + right_sz2
            int case1 = twoPointer(nums, sz1, 0, i) + twoPointer(nums,sz2, (i + 1), (n - 1));

            // case2: right_sz1 + left_sz2
            int case2 = twoPointer(nums, sz2, 0, i) + twoPointer(nums, sz1, (i + 1), (n - 1));

            ans = max({ans, case1, case2});
        }

        return ans;
    }
};