class Solution {
public:

    bool check(string s1, string s2, string t){

        int n = s1.size(), m = s2.size();
        int curr1 = 0; // for s1
        int curr2 = 0; // for s2
        int j = 0; // for t
        int k = t.size(); // rotating...

        while(curr1 < n){
            if(t[j] != s1[curr1])
                return false;
            j = (j + 1) % k;
            curr1++;
        }

        j = 0;
        while(curr2 < m){
            if(t[j] != s2[curr2])
                return false;
            curr2++;
            j = (j + 1) % k;
        }
        
        return (curr1 == n && curr2 == m);
    }
    string gcdOfStrings(string s1, string s2) {

        // we need to get largest substring common in both strings..
        // smallest t such that str1 = n * t and str2 = m * t, here n and m are integers

        vector<string> ss; // sample space
        int n = s1.size(), m = s2.size();
        string token = "";

        if(n < m) {
            // s1 < s2
            for(char ch : s1){
                token += ch;
                if(s1.size() % token.size() == 0 && s2.size() % token.size() == 0){
                    ss.push_back(token);
                }
            }
        }

        else{

            for(char ch : s2){
                token += ch;
                if(s1.size() % token.size() == 0 && s2.size() % token.size() == 0){
                    ss.push_back(token);
                }
            }

        }

        sort(ss.rbegin(), ss.rend());
        string ans = "";
        for(string s : ss){
            if(check(s1, s2, s)){
                ans = s;
                break;
            }
        }

        return ans;

        
        
    }
};