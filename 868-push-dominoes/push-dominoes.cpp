class Solution {
public:
    string pushDominoes(string dominoes) {

        // leftclosestRight
        // rightclosestLeft

        int n = dominoes.size();
        vector<int> leftclosestRight(n), rightclosestLeft(n);
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R'){
                leftclosestRight[i] = i;
            }
            else if(dominoes[i] == 'L'){
                leftclosestRight[i] = -1; // since, this left will neutralize the effect of R from  leftclosestright[i - 1]
            }
            else{
                if(i == 0){
                    leftclosestRight[i] = -1;
                }
                else{
                    leftclosestRight[i] = leftclosestRight[i - 1];
                }
            }
        }

        for(int i = (n - 1); i >= 0; i--){

            // rightclosestLeft
            if(dominoes[i] == 'L'){
                rightclosestLeft[i] = i;
            }
            else if(dominoes[i] == 'R'){
                rightclosestLeft[i] = -1; // same, this left will neutralie effect of right from after there..
            }
            else{
                if(i == n - 1)
                    rightclosestLeft[i] = -1;
                else
                    rightclosestLeft[i] = rightclosestLeft[i + 1];
            }
        }

        string ans = "";
        for(int i = 0; i < n; i++){
            if(leftclosestRight[i] == rightclosestLeft[i]){
                ans += '.';
            }
            else if(leftclosestRight[i] == -1){
                ans += 'L';
            }
            else if(rightclosestLeft[i] == -1){
                ans += 'R';
            }
            else{

                int left_distance = abs(i - leftclosestRight[i]);
                int right_distance = abs(i - rightclosestLeft[i]);

                if(left_distance < right_distance){
                    ans += 'R';
                }
                else if(left_distance > right_distance){
                    ans += 'L';
                }
                else{
                    ans += '.';
                }
            }
        }

        return ans;
        
    }
};