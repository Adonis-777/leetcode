class Solution {
public:

    bool check(vector<int>& nums, int val, int k){

        

        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; ){

            if(nums[i] <= val){
                count++;
                i += 2;
            }
            else{
                i++;
            }

            if(count >= k)
                return true;
        }

        return count >= k;
    }
    int minCapability(vector<int>& nums, int k) {

        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());
        int ans = h;

        while(l <= h){

            int mid = l + (h - l) / 2;
            if(check(nums, mid, k)){
                ans = min(ans, mid);
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
        
    }
};