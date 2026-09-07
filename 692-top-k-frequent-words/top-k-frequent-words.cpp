class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        auto cmp = [](const pair<int,string>& a, const pair<int,string>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;                         
        };

        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> pq(cmp);
        map<string, int> mp;

        for(string s : words){
            mp[s]++;
        }

        for(auto it : mp){
            pq.push({it.second, it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};