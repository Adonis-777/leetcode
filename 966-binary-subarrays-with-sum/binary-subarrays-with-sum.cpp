class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // curr - goal == pref
        int n = nums.size();
        map<int, int> mp;
        mp[0]++;
        
        int curr = 0, count = 0;
        for(int x : nums){
            curr += x;
            int comp = curr - goal;
            count += mp[comp];
            mp[curr]++;
        }

        return count;
        
    }
};