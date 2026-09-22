class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> last_seen(26, -1);
        for(int i = 0; i < s.size(); i++){
            last_seen[s[i] - 'a'] = i;
        }

        int curr = 0, last = 0, end = 0;
        vector<int> ans;

        while(curr <= end){

            end = max(end, last_seen[s[curr] - 'a']);
            if(curr == end){

                int distance = end - last + 1;
                ans.push_back(distance);
                last = curr + 1;
                //curr++;
            }

            curr++;
            if(curr < s.size())
                end = max(end, last_seen[s[curr] - 'a']);
            else
                break;

        }
        
        return ans;
    }
};