
class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {

        int n = nums.size();

        vector<int> minimum(n);
        minimum[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--){
            minimum[i] = min(minimum[i + 1], nums[i]);
        }

        int bucket = 1;
        int max_value = nums[0];

        for(int i = 0; i < n - 1; i++){

            max_value = max(max_value, nums[i]);

            if(max_value <= minimum[i + 1]){
                bucket++;
            }
        }

        return bucket;
    }
};
