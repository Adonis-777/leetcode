class Solution {
public:

    vector<vector<int>> ans;

    void twoSum(vector<int>& nums, int i, int n){

        int curr = nums[i];
        int l = i + 1, r = (n - 1);

        while(l < r){

            int sum = curr + nums[l] + nums[r];
            if(sum < 0){
                l++;
            }
            else if(sum > 0){
                r--;
            }
            else{

                vector<int> temp;        
                temp.push_back(nums[i]);
                temp.push_back(nums[l]);
                temp.push_back(nums[r]);
            
                ans.push_back(temp);
                while(l < r && nums[l] == nums[l + 1]){
                    l++;
                }
                l++;
                r--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            twoSum(nums, i, n);
        }

        return ans;    
    }
};