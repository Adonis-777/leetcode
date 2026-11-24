class Solution {
public:

    void transpose(vector<vector<int>>& a){
        for(int i = 0; i < a.size(); i++){
            for(int j = i + 1; j < a.size(); j++){

                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
        
            }
        }
    }

    void  reverse(vector<vector<int>> &a){
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < (a.size() / 2); j++){
                int temp = a[i][j];
                a[i][j] = a[i][a.size() - j - 1];
                a[i][a.size() - j - 1] = temp;
            }
        }
    }
    void rotate(vector<vector<int>>& a) {

        

        transpose(a);
        reverse(a);
        
    }
};