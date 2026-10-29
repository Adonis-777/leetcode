class Solution {
public:



    void GenAns(vector<int>& nums, int index, int currSum, vector<int>& curr, int target, vector<vector<int>> & ans){

        if(currSum == target){
            
            ans.push_back(curr);
            return;
        }
        else if(currSum > target){
            // there is no point only
            return;
        }
        if(index == nums.size()){
            return; // termination condition
        }

        for(int i = index; i < nums.size(); i++){

            if(i > index && nums[i] == nums[i - 1])
                continue;
                // duplicacy condition

            currSum += nums[i];
            curr.push_back(nums[i]);

            GenAns(nums, i + 1, currSum, curr, target, ans);

            currSum -= nums[i];
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;
        int currSum = 0;
        
        GenAns(candidates, 0, currSum, curr, target, ans);
        return ans;
    }
};