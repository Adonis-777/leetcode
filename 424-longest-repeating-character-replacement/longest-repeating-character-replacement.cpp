class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int  maxFrequency = 0;
        map<char, int> mp;

        int j = 0;
        int maxLen = 0;

        for(int i = 0; i < n; i++){

            mp[s[i]]++;
            maxFrequency = max(maxFrequency, mp[s[i]]);

            while((i - j + 1) - maxFrequency > k){
                mp[s[j]]--;
                j++;
            }

            maxLen = max(maxLen, i - j + 1);
        }

        return maxLen;
        
    }
};