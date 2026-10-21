class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();
        int j = 0;
        map<int, int> mp;

        for(int i = 0; i < n; i++){

            mp[nums[i]]++;

            if(mp[nums[i]] > 1)
                return true;

            while(i - j >= k){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
        }

        return false;
    }
};