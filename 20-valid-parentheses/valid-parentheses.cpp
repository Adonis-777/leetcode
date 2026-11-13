class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else{

                char comp;

                if(c == ')'){
                    comp = '(';
                }
                else if(c == ']'){
                    comp = '[';
                }
                else{
                    comp = '{';
                }

                if(!st.empty() && st.top() == comp){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();
        
    }
};