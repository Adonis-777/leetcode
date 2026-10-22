class Solution {
public:

    typedef long long ll;
    bool check(vector<int>& time, ll total_time, int totalTrips){

        // for this total time, can we make totalTrips or not
        ll trips = 0;
        for(int t : time){
            trips += (ll)total_time / t;

            if(trips >= totalTrips)
                return true;
        }

        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        ll l = 1, h = (ll)*min_element(time.begin(), time.end()) * (ll)totalTrips;
        ll ans = h;
        while(l <= h){

            ll mid = l + (h - l) / 2;
            if(check(time, mid, totalTrips)){
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