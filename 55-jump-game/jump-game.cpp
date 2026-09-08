class Solution {
public:
    bool canJump(vector<int>& nums) {

        int longest_stride = 0;

        for(int i = 0; i < nums.size(); i++){

            if(i > longest_stride)
                return false;
            longest_stride = max(longest_stride, i + nums[i]);
        }

        return true;
        
    }
};