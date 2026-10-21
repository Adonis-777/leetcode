class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int n = s.size();
        int cost = 0, j = 0, maxLen = 0;
        
        for(int i = 0; i < n; i++){
            cost += abs(s[i] - t[i]);

            while(cost > maxCost){
                int temp = abs(s[j] - t[j]);

                cost -= temp;

                j++;
            }

            int len = i - j + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
        
    }
};