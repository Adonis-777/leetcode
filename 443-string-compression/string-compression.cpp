class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int i = 0;
        int j = 0;
        int length = 0;

        while (i < n) {
            char current = chars[i];
            int start = i;

            while (i < n && chars[i] == current) {
                i++;
            }


            chars[j++] = current;

            if ((i - start) > 1) {
                string s = to_string((i - start));
                for (char c : s) {
                    chars[j++] = c;
                }
            }
        }

        return j;

    }
};