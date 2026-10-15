class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();
        int j = n - 1;

        while(j >= 0 && digits[j] > 8){
            digits[j] = 0;
            j--;
        }
        if(j == -1){
            digits.insert(digits.begin(), 1);
        }
        else{
            digits[j]++;
        }

        return digits;
        
    }
};