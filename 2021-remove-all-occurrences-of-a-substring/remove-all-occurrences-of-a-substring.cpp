class Solution {
public:
    string removeOccurrences(string s, string part) {

        int k = part.size();

        string st;

        for(char c : s){
            st.push_back(c);

            if(st.size() >= k && st.substr(st.size() - k, k) == part){
                st.erase(st.end() - k, st.end());
            }
        }

        return st;
        
    }
};