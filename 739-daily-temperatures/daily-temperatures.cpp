class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        vector<int> ans(n);
        map<int, int> mp;
        stack<int> st;

        for(int i = (n - 1); i >= 0; i--){

            while(!st.empty() && st.top() <= temp[i]){
                st.pop();
            }
            if(!st.empty()){
                int diff = mp[st.top()] - i;
                ans[i] = diff;
            }
            else{
                ans[i] = 0;
            }

            mp[temp[i]] = i;
            st.push(temp[i]);
        }

        return ans;
    }
};