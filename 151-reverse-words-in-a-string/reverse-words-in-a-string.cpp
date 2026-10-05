class Solution {
public:
    string reverseWords(const string& s) {
        vector<string> words;
        string token;

        for (char ch : s) {
            if (ch == ' ') {
                if (!token.empty()) {
                    
                    words.push_back(token);
                    token.clear();

                }
            } else {
                token += ch;
            }
        }

        if (!token.empty()) {
            words.push_back(token);
        }

        reverse(words.begin(), words.end());
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            
            if(i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};