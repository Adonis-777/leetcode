class Solution {
public:

    bool check(vector<int>&nums, int penalty, int maxOp){

        int op = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int quo = (nums[i] + penalty - 1) / penalty;
            op += (quo - 1);
            if(op > maxOp)
                return false;
        }

        return op <= maxOp;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1, h = nums[n - 1];
        int ans;

        while(l <= h){
            int mid = l + (h - l) / 2;

            if(check(nums, mid, maxOperations)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};