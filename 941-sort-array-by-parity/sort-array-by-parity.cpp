class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        map<int, int> even, odd;
        for(int x : nums){
            if(x % 2 == 0){
                even[x]++;
            }
            else{
                odd[x]++;
            }
        }

        int i = 0;
        for(auto it : even){

            while(it.second--){
                nums[i++] = it.first;
            }
        }

        for(auto it : odd){
            while(it.second--){
                nums[i++] = it.first;
            }
        }

        return nums;
    
        
    }
};