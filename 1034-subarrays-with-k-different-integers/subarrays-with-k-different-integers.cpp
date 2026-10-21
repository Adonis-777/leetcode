class Solution {
public:

    int twoPointer(vector<int>& nums, int k){

        int n = nums.size();
        int count = 0;
        int j = 0;

        map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;

            while(mp.size() > k){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }

            count += (i - j + 1);
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return twoPointer(nums, k) - twoPointer(nums, (k - 1));
        
    }
};