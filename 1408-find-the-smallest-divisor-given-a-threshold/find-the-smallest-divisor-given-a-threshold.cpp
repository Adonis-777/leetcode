class Solution {
public:

    bool check(vector<int>& nums, int div, int threshold){

        int sum = 0;

        for(int x : nums){

            if(x < div){
                sum += 1;
            }
            else{
                sum += (x + div - 1) / div;
            }
        }

        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int l = 1, h = 1e6;
        int ans;
        
        while(l <= h){

            int mid = l + (h - l) / 2;
            if(check(nums, mid, threshold)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};