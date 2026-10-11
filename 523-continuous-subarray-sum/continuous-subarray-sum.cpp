class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        map<int, int> mp;
        int  curr = 0;
        mp[0] = 0;
        
        for(int i = 0; i < n; i++){
            curr += nums[i];

            if(curr % k == 0 && i >= 1)
                return true;
            
            int comp = curr % k;

            if(mp.count(comp)){
                int len = i - mp[comp];
                if(len >= 2)
                    return true;
            }
            else{
                mp[curr % k] = i;
            }
        }

        return false;
        
    }
};