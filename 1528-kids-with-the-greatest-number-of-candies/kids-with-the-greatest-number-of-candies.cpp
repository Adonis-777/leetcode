class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        int n = candies.size();
        vector<int> maxbf(n), maxaf(n);
        maxbf[0] = candies[0];
        for(int i = 1; i < n; i++){
            maxbf[i] = max(candies[i], maxbf[i - 1]);
        }

        maxaf[n - 1] = candies[n - 1];
        for(int i = (n - 2); i >= 0; i--){
            maxaf[i] = max(candies[i], maxaf[i + 1]);
        }

        vector<bool> ans(n);
        for(int i = 0; i < n; i++){

            if(i == 0){
                if(candies[i] + extraCandies >= maxaf[i + 1]){
                    ans[i] = true;
                }
                else{
                    ans[i] = false;
                }
            }

            else if(i == (n - 1)){
                if(candies[i] + extraCandies >= maxbf[i - 1]){
                    ans[i] = true;
                }

                else{
                    ans[i] = false;
                }
            }

            else{

                int curr = candies[i] + extraCandies;
                if(curr >= maxbf[i - 1] && curr >= maxaf[i + 1]){
                    ans[i] = true;
                }
                else{
                    ans[i] = false;
                }
            }
        }

        return ans;
        
    }
};