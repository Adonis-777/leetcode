class Solution {
public:

    int myOwn(vector<int>& nums, int l, int h){
        if(l > h)
            return -1;
        int mid = l + (h - l) / 2;
        if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
            return mid;
        return max(myOwn(nums, l, mid - 1), myOwn(nums, mid + 1, h));
    }
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();
        if(n == 1){
            return 0;
        }

        if(nums[0] > nums[1])
            return 0;
        if(nums[n - 1] > nums[n - 2])
            return (n - 1);
        
        return myOwn(nums, 1, (n - 2));
        
    }
};