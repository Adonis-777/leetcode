class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int n = nums.size();
        if(n < 3)  
            return false;
        if(is_sorted(nums.begin(), nums.end()))
            return false;
        
        vector<int> min(n, INT_MIN), max(n, INT_MIN);
        min[0] = nums[0];
        for(int i = 1; i < (n - 1); i++){
            min[i] = (nums[i] < min[i - 1]) ? nums[i] : min[i - 1];
        }
        

        // for making max array such that nums[i] > stack top
        // i.e while(!stack.empty() && nums[i] <= stack.top()) stack.pop(), if stack.empty == true, then max[i] = -1 or use multiset and do binary search ig

        multiset<int> ms;
        for (int i = n - 2; i >= 0; i--) {
            ms.insert(nums[i + 1]);
            auto it = ms.lower_bound(nums[i]); // first element >= nums[i]
            if (it != ms.begin()) {
                --it;
                max[i] = *it;               // largest element strictly < nums[i]
            }
        }

        for(int i = 1; i < (n - 1); i++){

            int curr = nums[i];
            int left = min[i - 1];
            int right = max[i];

            if(right == INT_MIN)
                continue;
            if(curr > right && right > left)
                return true;
        }

        return false;
    }
};