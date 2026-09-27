class Solution {
public:
    string reverseParentheses(string s) {

        stack<string> st;
        string curr = "";

        for(char ch : s) {

            if(ch == '(') {

                // Store everything collected so far
                st.push(curr);

                // Start fresh for content inside ()
                curr = "";
            }

            else if(ch == ')') {

                // Reverse the current substring
                reverse(curr.begin(), curr.end());

                // Get the string before this '('
                string prev = st.top();
                st.pop();

                // Combine them
                curr = prev + curr;
            }

            else {

                curr += ch;
            }
        }

        return curr;
    }
};