class Solution {
public:

    bool check(vector<int>& nums, int p, int allowed){
        int count = 0;
        int n = nums.size();
        for(int i = 1; i < n; ){
            if(nums[i] - nums[i - 1] <= allowed){
                
                count++;
                i += 2;
            }
            else{
                i++;
            }

            if(count >= p)
                return true;
        }

        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, h = nums[n - 1] - nums[0];
        int ans;

        while(l <= h){

            int mid = l + (h - l) / 2;
            if(check(nums, p, mid)){
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