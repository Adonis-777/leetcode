class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string token = "";

        path += '/';

        for(char ch : path){
            
            if(ch != '/'){
                token += ch;
                continue;
            }

            // when ch == '/'
            if(token == "."){
                // current directory only, dont add or remove anything
                token = "";
                continue;
            }

            if(token == ".."){

                // parent directory                
                if(!st.empty()){
                    st.pop();
                }

                token = "";
                continue;
            }

            else{
                // some random directory
                if(!token.empty()){
                    st.push(token);
                }

                token = "";                
            }
        }

        string ans = "";
        vector<string> temp;
        while(!st.empty()){
            token = st.top();
            temp.push_back(token);

            st.pop();
        }

        ans += '/';

        reverse(temp.begin(), temp.end());
        
        for(int i = 0; i < temp.size(); i++){
            string s = temp[i];
            ans += s;

            if(i != (temp.size() - 1))
                ans += '/';
        }            

        return ans;
        
    }
};