class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<int> maximum(n, 0), minimum(n, 0);

        maximum[n - 1] = prices[n - 1];
        for(int i = n - 2; i >= 1; i--){
            maximum[i] = max(prices[i], maximum[i + 1]);
        }

        minimum[0] = prices[0];
        for(int i = 1; i < n; i++){
            minimum[i] = min(prices[i], minimum[i - 1]);
        }

        int ans = 0;
        for(int i = 0; i < (n - 1); i++){
            int temp = maximum[i + 1] - minimum[i];
            ans = max(ans, temp);
        }

        return ans;
        
    }
};