class Solution {
public:
    
    bool check(vector<int>& nums, int lim, int cap){

        int hours = 0;
        for(int x : nums){
            hours += (x + cap - 1) / cap;
            if(hours > lim)
                return false;
        }

        return hours <= lim;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(check(piles, h, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }


        return ans;
        
    }
};