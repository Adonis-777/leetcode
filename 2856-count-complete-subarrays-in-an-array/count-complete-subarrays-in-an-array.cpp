class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        int n = nums.size();
        set<int> s;

        for(int x : nums){
            s.insert(x);
        }

        map<int, int> mp;
        int j = 0;

        int count = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;

            

            while(mp.size() == s.size()){

                count += (n - i);

                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
                }

                j++;
            }
        }

        return count;

        
    }
};