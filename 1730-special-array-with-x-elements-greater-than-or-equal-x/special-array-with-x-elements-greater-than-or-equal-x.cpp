class Solution {
public:

    bool check(vector<int>& nums, int val){

        int freq = 0;
        for(int x : nums){
            if(x >= val){
                freq++;
            }
        }

        return freq >= val;
    }
    int count(vector<int> nums, int val){

        int freq = 0;
        for(int x : nums){
            if(x >= val){
                freq++;
            }
        }

        return freq;
    }
    int specialArray(vector<int>& nums) {

        int n = nums.size();
        int l = 1, h = n;
        int ans = -1;
        while(l <= h){
            int mid = l + (h - l) / 2;

            if(check(nums, mid)){
                if(count(nums, mid) == mid){
                    ans = max(ans, mid);
                }
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }

        return ans;
        
    }
};