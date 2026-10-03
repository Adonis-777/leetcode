class Solution {
public:
    int longestValidParentheses(string s) {

        // left --> right: open > close
        int open = 0, close = 0;
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){

            if(s[i] == '('){
                open++;
            }
            else if(s[i] == ')'){
                close++;
            }
            if(open == close){
                ans = max(ans, close + open);
            }
            else if(close > open){
                close = 0;
                open = 0;
            }
        }

        // rigth --> left: close > open
        open = 0;
        close = 0;

        for(int i = (n - 1); i >= 0; i--){
            if(s[i] == ')'){
                close++;
            }
            else if(s[i] == '('){
                open++;
            }
            if(open == close){
                ans = max(ans, open + close);
            }
            else if(open > close){
                open = 0;
                close = 0;
            }
        }

        return ans;
        
    }
};