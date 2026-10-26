class Solution {
public:
    typedef long long ll;

    bool check(vector<int>& candies, ll mid, ll k){

        ll count = 0;
        for(int p : candies){
            count += (p / mid);
            if(count >= k)
                return true;
        }
        return count >= k;
    }


    int maximumCandies(vector<int>& candies, long long k) {

        ll l = 1, h = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while(l <= h){
            ll mid = l + (h - l) / 2;
            
            if(check(candies, mid, k)){
                ans = mid;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }

        return ans;
        
    }
};