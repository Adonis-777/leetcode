class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int token = nums[0];
        int freq = 1;

        vector<int> ans;
        for(int i = 1; i < n; i++){

            if(nums[i] != nums[i - 1]){
                if(freq > (n / 3)){
                    ans.push_back(token);
                }
                token = nums[i];
                freq = 1;

                continue;
            }
            freq++;
        }

        if(freq > (n / 3))
            ans.push_back(token);

        return ans;
        
    }
};