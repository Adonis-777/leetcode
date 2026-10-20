class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {


        int minLen = INT_MAX;
        int n = nums.size();
        int j = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];

            while(sum >= target){
                int len = i - j + 1;
                minLen = min(minLen, len);
                sum -= nums[j++];
            }

        }

        return minLen == INT_MAX ? 0 : minLen;
        
        
    }
};