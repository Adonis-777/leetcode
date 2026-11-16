class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.size();
        vector<bool> visit(n, true);

        stack<int> left, right;

        for(int i = 0; i < n; i++){
            char c = s[i];

            if(c == '('){
                left.push(i);
            }
            else if(c == ')'){
                if(!left.empty())
                    left.pop();
                else
                    right.push(i);
                
            }
        }

        while(!right.empty()){
            int i = right.top();
            visit[i] = false;
            right.pop();
        }

        while(!left.empty()){
            int i = left.top();
            visit[i] = false;
            left.pop();
        }

        

        string ans = "";
        for(int i = 0; i < n; i++){
            if(visit[i]){
                ans += s[i];
            }
        }

        return ans;
        
    }
};