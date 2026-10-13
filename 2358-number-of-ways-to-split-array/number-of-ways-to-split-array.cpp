class Solution {
public:
    typedef long long ll;
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size(), count = 0;
        ll curr = 0, total = 0;

        for(int x : nums){
            total += (ll)x;
        }

        for(int i = 0; i < (n - 1); i++){
            curr += (ll)nums[i];

            if(curr >= (total - curr)){
                count++;
            }
        }

        return count;

    }
};