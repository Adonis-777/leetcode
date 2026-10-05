class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        int zero_count = 0;
        vector<int> zero_present(n, 0);

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zero_present[i] = 1;
                zero_count++;
                if(zero_count > 1)
                    break;
            }
        }

        if(zero_count > 1){
            vector<int> ans(n, 0);
            return ans;
        }

        if(zero_count == 1){
            vector<int> ans(n);
            int product = 1;

            for(int i = 0; i < n; i++){
                if(nums[i] != 0){

                    ans[i] = 0;
                    product *= nums[i];

                }
            }

            for(int i = 0; i < n; i++){
                if(zero_present[i]){
                    ans[i] = product;
                    break;
                }
            }
            
            return ans;
        }

        int product = 1;
        for(int i = 0; i < n; i++){
            product *= nums[i];
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = product / nums[i];
        }

        return ans;
        
    }
};