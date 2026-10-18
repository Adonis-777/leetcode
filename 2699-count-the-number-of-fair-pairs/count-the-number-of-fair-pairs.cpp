class Solution {
public:

    typedef long long ll;

    ll twoPointer(vector<int> &nums, int target){

        int i = 0, j = nums.size() - 1;
        ll count = 0;

        while(i < j){
            ll sum = (ll)nums[i] + (ll)nums[j];
            if(sum <= (ll)target){
                count += (ll)(j - i);
                i++;
            }
            else{
                j--;
            }
        }

        return count;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        sort(nums.begin(), nums.end());
        return twoPointer(nums, upper) - twoPointer(nums, (lower - 1));

        
    }
};