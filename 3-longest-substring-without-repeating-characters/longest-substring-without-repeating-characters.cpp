class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> mp;
        int j = 0;
        int n = s.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    mp.erase(s[j]);
                }
                j++;
            }

            int len = i - j + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
        
    }
};