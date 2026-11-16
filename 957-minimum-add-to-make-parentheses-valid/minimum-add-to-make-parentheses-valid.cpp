class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> left, right;
        for(char c : s){
            if(c == '('){
                left.push(c);
            }
            else{
                if(left.empty()){
                    right.push(c);
                }
                else{
                    left.pop();
                }
            }
        }

        return (left.size() + right.size());
        
    }
};