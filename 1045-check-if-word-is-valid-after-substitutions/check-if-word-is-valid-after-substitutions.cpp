class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 3 != 0)
            return false;
        
        string stack;
        for(char c : s){
            stack.push_back(c);

            if(stack.size() >= 3 && stack.substr(stack.size() - 3, 3) == "abc")
                stack.erase(stack.end() - 3, stack.end());

        }

        return stack.empty();
    }
};