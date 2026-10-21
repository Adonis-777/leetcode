class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int k = 0;
        for(int x : nums){
            if(x == 1)
                k++;
        }
        vector<int> temp(nums.begin(), nums.end());
        for(int x : temp)
            nums.push_back(x);

        int n = nums.size();
        int j = 0;

        int zero_count = 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                zero_count++;
            
            if(i - j + 1 > k){
                if(nums[j] == 0)
                    zero_count--;
                j++;
            }

            if(i - j + 1 == k)
                ans = min(ans, zero_count);
        }

        return ans;
    
    }
};