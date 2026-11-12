class Solution {
public:

    typedef long long ll;

    bool check(vector<int> nums, int lim){
        int n = nums.size();

        vector<ll> temp(n);
        for(int i = 0; i < n; i++){
            temp[i] = (ll)nums[i];
        }
        for(int i = n - 1; i >= 1; i--){
            if(temp[i] > lim){  
                ll op = temp[i] - lim;
                temp[i - 1] += op;
                temp[i] = nums[i] - op;
            }
        }

        return *max_element(temp.begin(), temp.end()) <= lim;
    }
    int minimizeArrayValue(vector<int>& nums) {
        
        int l = *min_element(nums.begin(), nums.end()), h = *max_element(nums.begin(), nums.end());

        int ans = h;
        while(l <= h){
            int mid = l + (h - l) / 2;

            if(check(nums, mid)){
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