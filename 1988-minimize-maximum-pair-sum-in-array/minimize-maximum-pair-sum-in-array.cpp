class Solution {
public:
    int minPairSum(vector<int>& nums) {

        int ans = INT_MIN;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int i = 0, j = n - 1;

        while(j - i >= 1){

            int temp = nums[i] + nums[j];
            ans = max(ans, temp);
            i++;
            j--;
        }

        return ans;
    
    }
};