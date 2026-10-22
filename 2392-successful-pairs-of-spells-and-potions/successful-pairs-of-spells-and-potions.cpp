class Solution {
public:

    int helper(int mul, vector<int>& potions, long long success){

        int n = potions.size();
        int pos = n;


        int l = 0, h = n - 1;
        while(l <= h){

            int mid = l + (h - l) / 2;
            // mul * potions[i] < success --> move forward (l = mid + 1)
            // else --> ans = min(ans, i) and h = mid - 1

            long long product = (long long)mul * potions[mid];
            if(product < success){
                l = mid + 1;
            }
            else{
                pos = min(pos, mid);
                h = mid - 1;
            }
        }


        return n - pos;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> ans(spells.size());
        for(int i = 0; i < spells.size(); i++){
            ans[i] = helper(spells[i], potions, success);
        }

        return ans;
    }
};