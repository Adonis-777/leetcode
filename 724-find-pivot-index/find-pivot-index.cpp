class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int total = 0;

        for(int x : nums){
            total += x;
        }

        int curr = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(curr == (total - nums[i] - curr))
                return i;
            curr += nums[i];
        }
        
        return -1;
    }
};