class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        map<string, int> mp;
        for (string s : strs) {

            string temp = "";
            for (char c : s) {
                temp += c;
                mp[temp]++;
            }
        }

        string ans = "";
        int maxFrequency = strs.size();
        for (auto it : mp) {
            maxFrequency = max(maxFrequency, it.second);
        }

        for (auto it : mp) {
            if (it.second == maxFrequency) {
                ans = it.first;
            }
        }

        return (string)ans;

    }
};