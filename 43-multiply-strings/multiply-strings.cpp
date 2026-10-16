class Solution {
public:
    string multiply(string num1, string num2) {

        int n = num1.size(), m = num2.size();

        if(num1 == "0" || num2 == "0")
            return "0";
        vector<int> temp(n + m, 0);

        for(int i = n - 1; i >= 0; i--){

            for(int j = m - 1; j >= 0; j--){

                int mul = (num1[i] - '0') * (num2[j] - '0');

                temp[i + j + 1] += mul;
                temp[i + j] += temp[i + j + 1] / 10;
                temp[i + j + 1] %= 10;

            }
        }

        int i = 0; 
        while(temp[i] == 0)
            i++;
        
        string ans = "";
        while(i < (n + m)){
            ans += to_string(temp[i]);
            i++;
        }

        return ans;
    }
};