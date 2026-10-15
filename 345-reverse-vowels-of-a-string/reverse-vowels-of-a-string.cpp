class Solution {
public:

    bool vowel(char ch){

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {

        int n = s.size();
        string ans = "";
        
        int j = (n - 1);
        for(int i = 0; i < n; i++){

            char ch = s[i];
            if(vowel(ch)){
                while(!vowel(s[j]))
                    j--;
                ans += s[j];
                j--;
            }
            else{
                ans += ch;
            }
        }
        

        return ans;
    }
};