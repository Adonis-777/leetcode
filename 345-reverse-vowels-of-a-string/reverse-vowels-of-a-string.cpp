class Solution {
public:
    string reverseVowels(string s) {
        
        vector<char> temp;
        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                temp.push_back(ch);
            }
        }

        reverse(temp.begin(), temp.end());
        string ans = "";
        int i = 0;
        for(char ch : s){
            
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                ans += temp[i++];
            }
            else{
                ans += ch;
            }
        }

        return ans;
    }
};