class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int maxvalue = values[0];

        for(int i = 1; i < n; i++){
            int temp = values[i] + maxvalue - i;
            maxvalue = max(maxvalue, values[i] + i);
            ans = max(ans, temp);
        }

        return ans;
    }
};