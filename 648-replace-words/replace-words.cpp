class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        set<string> s;
        for (string str : dictionary)
            s.insert(str);

        string ans = "";
        // we want to break the string into string vector
        stringstream ss(sentence);
        string word;
        vector<string> temp;

        while (ss >> word)
            temp.push_back(word);

        for (string str : temp) {
            string token = "";
            int f = 0;

            for (char ch : str) {
                token += ch;
                if (s.count(token)) {
                    ans += token;
                    ans += " ";
                    f = 1;
                    break;
                }
            }

            if (f == 1)
                continue;

            ans += token;
            ans += " ";
        }

        if(!ans.empty())
            ans.pop_back();
            
        return ans;

    }
};