class Solution {
public:

    bool isPalindrome(string s){
        
        int n = s.size();
        for(int i = 0; i < (n / 2); i++){
            if(s[i] != s[n - 1 - i]) return false;
        }

        return true;
    }
    int countSubstrings(string s) {

        int n = s.size();
        int count = 0;

        //bool dp[n][n];

        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    dp[i][j] = true;
                    count++;
                }
            }
        }

        for(int i = 0; i < (n - 1); i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                count++;
            }
        }


        for(int length = 3; length <= n; length++){

            int i = 0;
            while(i < (n - length + 1)){
                int j = i + length - 1;

                if(s[i] == s[j]){
                    if(dp[i + 1][j - 1] == true){
                        dp[i][j] = true;
                        count++;
                    }
                }

                i++;
            }
        }

        return count;

        
    }
};