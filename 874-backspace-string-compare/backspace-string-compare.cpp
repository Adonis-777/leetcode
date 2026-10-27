class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> st1, st2;

        for(char c : s){
            if(c == '#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }
            else{
                st1.push(c);
            }
        }

        string s1 = "", t1 = "";
        while(!st1.empty()){
            s1 += st1.top();
            st1.pop();
        }


        for(char c : t){
            if(c == '#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }
            else{
                st2.push(c);
            }
        }

        while(!st2.empty()){
            t1 += st2.top();
            st2.pop();
        }

        return s1 == t1;
        
        
    }
};