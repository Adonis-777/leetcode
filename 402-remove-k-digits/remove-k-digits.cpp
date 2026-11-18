class Solution {
public:
    string removeKdigits(string s, int k) {
        
        int n = s.size();

        string res = "";
        stack<char> st;

        st.push(s[0]);

        for(int i = 1; i < n; i++){


            while(k > 0 && !st.empty() && s[i] < st.top()){
                k--;
                st.pop();
            }

            st.push(s[i]);
        }

        while(k && !st.empty()){
            k--;
            st.pop();
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0; 
        while(i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        
        if(res.size() == 0) return "0";

        return res;
    }
};