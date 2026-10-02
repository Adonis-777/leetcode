class Solution {
public:
    vector<string> samplespace;
    string token = "";

    void genParanthesis(int n){

        if(token.size() == (2*n)){
            samplespace.push_back(token);
            return;
        }

        token += '(';
        genParanthesis(n);
        token.pop_back();

        token += ')';
        genParanthesis(n);
        token.pop_back();
    }

    bool check(string s){
        stack<char> st;

        for(char ch : s){

            if(ch == '('){
                st.push(ch);
            }

            else{
                if(st.empty())
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }

    vector<string> validate(){
        vector<string> ans;

        for(string s : samplespace){

            if(check(s)){
                ans.push_back(s);
            }
        }

        return ans;
    }

    
    vector<string> generateParenthesis(int n) {

        genParanthesis(n);

        vector<string> ans = validate();
        return ans;
        
    }
};