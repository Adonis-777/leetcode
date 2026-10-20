class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> mp;
        vector<int> ans;
        for(int x : nums){
            mp[x]++;
        }

        int n = nums.size();
        for(auto it : mp)
        {
            if(it.second > 1)
                ans.push_back(it.first);
        }
        
        for(int i = 1; i <= n; i++){
            if(!mp.count(i))
                ans.push_back(i);
        }

        

        return ans;
    }
};  