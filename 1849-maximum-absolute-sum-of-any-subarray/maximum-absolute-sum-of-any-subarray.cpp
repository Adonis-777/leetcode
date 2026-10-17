class Solution {
public:

    int kadaneMin(vector<int>& nums){
        int n = nums.size();
        int ans = INT_MAX;
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = min(sum + nums[i], nums[i]);
            ans = min(ans, sum);
        }

        return ans;
    }

    int kadaneMax(vector<int>& nums){
        int n = nums.size();
        int ans = 0, sum = 0;

        for(int i = 0; i < n; i++){
            sum = max(sum + nums[i], nums[i]);
            ans = max(ans, sum);
        }

        return ans;
    }
    int maxAbsoluteSum(vector<int>& nums) {


        return max(kadaneMax(nums), abs(kadaneMin(nums)));
        
    }
};