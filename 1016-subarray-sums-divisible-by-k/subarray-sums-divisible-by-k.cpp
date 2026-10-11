class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        map<int, int> mp;
        mp[0] = 1;
        int curr = 0, count = 0;

        for(int i = 0; i < n; i++){
    
            while(nums[i] < k)
                nums[i] += k;

            curr += nums[i];
            int comp = curr % k;
            count += mp[comp];

            mp[comp]++;
        }

        return count;
        
    }
};