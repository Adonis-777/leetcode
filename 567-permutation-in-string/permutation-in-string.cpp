class Solution {
public:

    bool checkInclusion(string s1, string s2) {

        int n = s1.size(), m = s2.size();
        if (n > m)
            return false;

        vector<int> mp1(26, 0), mp2(26, 0);
        for (char c : s1) {
            mp1[c - 'a']++;
        }

        int j = 0;
        for (int i = 0; i < m; i++) {

            mp2[s2[i] - 'a']++;

            while (i - j + 1 > n) {
                mp2[s2[j] - 'a']--;
                j++;
            }

            if (i - j + 1 == n) {
                if (mp1 == mp2)
                    return true;
            }

        }

        return false;

    }
};