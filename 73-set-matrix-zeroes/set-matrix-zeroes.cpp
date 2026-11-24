class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> r_flag(m, false), c_flag(n, false);


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(matrix[i][j] == 0){
                    r_flag[i] = true;
                    c_flag[j] = true;
                }
            }
        }

        for(int row = 0; row < m; row++){
            if(r_flag[row]){
                for(int col = 0; col < n; col++){
                    matrix[row][col] = 0;
                }
            }
        }

        for(int col = 0; col < n; col++){
            if(c_flag[col]){
                for(int row = 0; row < m; row++){
                    matrix[row][col] = 0;
                }
            }
        }
        
    }
};