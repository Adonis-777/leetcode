class Solution {
public:
    typedef long long ll;

    bool check(vector<int>& ranks, ll time, int cars) {
        ll repaired = 0;

        for (int r : ranks) {
            ll quo = sqrt((long double)time / r);
            repaired += quo;

            if (repaired >= cars)
                return true;
        }

        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {

        sort(ranks.rbegin(), ranks.rend());
        // lowest time --> car_count / maximum_number * car_counnt * car_count
        // highest time --> car_count / minimum_number * car_count * car_count

        ll l = 1;
        ll h = 1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars;  
        ll ans = h;

        while(l <= h){

            ll mid = l + (h - l) / 2;
            if(check(ranks, mid, cars)){
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


// while carcount > 0 --> 
/*

ll time_taken = 0;
for(int i = 0; i < n; i++){
    if(carcount <= 0)
        break;
    ll quo = cars / ranks[i];
    carcount -= quo
    time_taken += (rank[i] * quo * quo)
    if(time_taken > lim)
        return false;
}
return true;
*/