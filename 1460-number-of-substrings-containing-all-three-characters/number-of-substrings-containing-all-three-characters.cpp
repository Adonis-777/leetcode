class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        int j = 0;

        int count = 0;

        vector<int> mp(3, 0);
        for(int i = 0; i < n; i++){
            char ch = s[i];
            mp[ch - 'a']++;

            while(mp[0] >= 1 && mp[1] >= 1 && mp[2] >= 1){
                count += (n - i);

                char c = s[j];
                mp[c - 'a']--;

                j++;
            }
        }

        return count;
        
    }
};