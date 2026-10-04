class Solution {
public:
    string mergeAlternately(string w1, string w2) {

        int n = w1.size(), m = w2.size();
        string ans = "";
        if(n == m){
            int i = 0, j = 0;
            int turn = 0;

            while(i < n && j < m){
                if(turn % 2 == 0){
                    ans += w1[i++];
                    
                }
                else{

                    ans += w2[j++];
                }

                turn++;
            }

            ans += w2[j++];
        }


        else if(n < m){

            int i = 0, j = 0, turn = 0;

            while(i < n && j < m){
                if(turn % 2 == 0){
                    ans += w1[i++];
                }
                else{
                    ans += w2[j++];
                }
                turn++;
            }

            while(j < m){
                ans += w2[j++];
            }
        }

        else{

            int i = 0, j = 0, turn = 0;
            while(i < n && j < m){
                if(turn % 2 == 0){
                    ans += w1[i++];
                }
                else{
                    ans += w2[j++];
                }
                turn++;
            }

            while(i < n){
                ans += w1[i++];
            }
        }


        return ans;
        
    }
};