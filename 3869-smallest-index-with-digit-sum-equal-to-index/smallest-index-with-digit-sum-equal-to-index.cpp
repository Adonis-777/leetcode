class Solution {
public:

    int sum_of_digits(int num){
        int sum = 0;
        while(num > 0){
            int rem = num % 10;
            sum += rem;
            num = num / 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {

        int n = nums.size();
        int index = INT_MAX;

        for(int i = 0; i < n; i++){
            if(sum_of_digits(nums[i]) == i){
                index = min(index, i);
            }
        }
        
        return (index == INT_MAX) ? -1 : index;
    }
};