class Solution {
public:
    int reverseDegree(string s) {

        // char - 'a' ==> numerical value
        // so if char == a: 
        // char - 'a' = 0 ==> 26 - this value is reversed value

        int n = s.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            int mul = (i + 1);
            int val = s[i] - 'a';
            int mul2 = 26 - val;

            sum += mul * mul2;
        }

        return sum;
        
    }
};