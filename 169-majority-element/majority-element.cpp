class Solution {
public:
    int majorityElement(vector<int>& nums) {


        sort(nums.begin(), nums.end());
        // sorting for maintaining same elements adjacent to each other

        int n = nums.size();
        int ans = nums[0];
        int freq = 1;

        for(int i = 1; i < n; i++){

            if(nums[i] != nums[i - 1]){
                // breaking condition
                if(freq > (n / 2)){
                    return ans;
                }

                // else new possible answer
                ans = nums[i];
                freq = 1;
                continue;
            }

            // nums[i] == nums[i - 1]
            freq++;
        }
        

        // since the solution is guaranteed and if answer is not returned in loop itself, that means that current answer is only the true answer. So, we can just return that without checking

        return ans;
    }
};