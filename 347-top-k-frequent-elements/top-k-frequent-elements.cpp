class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        map<int, int> mp;

        for(int x : nums)
            mp[x]++;
        
        vector<pair<int, int>> v;
        for(auto it : mp){

            v.push_back({it.second, it.first});
        }

        sort(v.rbegin(), v.rend());
        int i = 0;
        int count = 0;

        vector<int> ans;
        while(i < v.size() && count < k){
            ans.push_back(v[i].second);
            i++;
            count++;
        }

        return ans;
        
    }
};