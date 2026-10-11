class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();
        map<int, int> mp;

        int ans = 0, curr = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }

        mp[0] = -1;
        for(int i = 0; i < n; i++){
            curr += nums[i];
            
            if(mp.count(curr)){
                int len = i - mp[curr];
                ans = max(ans, len);
            }
            else{
                mp[curr] = i;
            }
        }

        return ans;
        
    }
};