class Solution {
public:

    typedef pair<int, char> P;
    string reorganizeString(string s) {

        vector<int> ch(26);
        int n = s.size();

        for(char& c : s){
            ch[c - 'a']++;

            if(ch[c - 'a'] > (n + 1) / 2)
                return "";
        }


        priority_queue<P, vector<P>> pq;
        for(char c = 'a'; c <= 'z'; c++){

            if(ch[c-'a'] > 0){
                pq.push({ch[c - 'a'], c});
            }
        }

        string result = "";
        while(pq.size() >= 2){

            auto p1 = pq.top();
            pq.pop();

            auto p2 = pq.top();
            pq.pop();

            result += p1.second;
            p1.first--;

            result += p2.second;
            p2.first--;

            if(p1.first > 0){
                pq.push(p1);
            }

            if(p2.first > 0){
                pq.push(p2);
            }

        }

        if(!pq.empty()){
            result += pq.top().second;
        }

        return result;
        
    }
};