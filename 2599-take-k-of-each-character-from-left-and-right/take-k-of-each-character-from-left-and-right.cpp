class Solution {
public:
    int takeCharacters(string s, int k) {

        int n = s.size();
        vector<int> freq(3, 0), total(3, 0);
        for(char x : s){
            total[x - 'a']++;
        }

        freq[0] = total[0] - k;
        freq[1] = total[1] - k;
        freq[2] = total[2] - k;

        if(freq[0] < 0 || freq[1] < 0 || freq[2] < 0)
            return -1;
        
        int j = 0;
        vector<int> mp(3, 0);
        
        int maxLen = INT_MIN;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            mp[ch - 'a']++;

            while(mp[ch - 'a'] > freq[ch - 'a']){
                char c = s[j];
                mp[c - 'a']--;
                j++;
            }

            int len = i - j + 1;
            maxLen = max(maxLen, len);
        }

        return n - maxLen;
        
    }
};