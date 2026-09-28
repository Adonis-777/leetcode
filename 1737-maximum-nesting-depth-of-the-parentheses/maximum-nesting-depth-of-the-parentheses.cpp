class Solution {
public:
    int maxDepth(string s) {

        stack<char> st;
        int maxSize = 0;

        for(char c : s){

            if(c == '('){
                st.push(c);
            }
            else if(c == ')'){
                int size = st.size();
                maxSize = max(maxSize, size);
                st.pop();
            }
        }

        return maxSize;
        
    }
};