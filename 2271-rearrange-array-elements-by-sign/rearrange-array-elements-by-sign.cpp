class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> positive_indices, negative_indices;

        int n = nums.size();
        for (int i = 0; i < n; i++) {

            if (nums[i] > 0) {
                positive_indices.push_back(i);
            }
            else {
                negative_indices.push_back(i);
            }
        }

        vector<int> ans(n);
        int positive_index = 0, negative_index = 0;
        for (int i = 0; i < n; i++) {

            if (i % 2 == 0) {
                ans[i] = nums[positive_indices[positive_index++]];
            }
            else {
                ans[i] = nums[negative_indices[negative_index++]];
            }
        }

        return ans;

    }
};