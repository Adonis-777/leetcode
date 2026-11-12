class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();
        int i = 0, j = 0, ans = 0;

        // increasing part
        while(j < n){
                
            while((i + 1) < n && nums[i + 1] > nums[i]){
                i++;
            }

            int len = i - j + 1;
            ans = max(ans, len);
            i++;
            j = i;
        }

        
        // decreasing
        i = 0;
        j = 0;
        while(j < n){
                
            while((i + 1) < n && nums[i + 1] < nums[i]){
                i++;
            }

            int len = i - j + 1;
            ans = max(ans, len);
            i++;
            j = i;
        }

        return ans;

        
        
    }
};