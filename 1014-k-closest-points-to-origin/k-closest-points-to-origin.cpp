class Solution {
public:

    typedef long long ll;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<ll, vector<int>>> pq;

        for(auto it : points){
           
            ll distance = ((ll)it[0] * it[0] + (ll)it[1] * it[1]);
           

            pq.push({distance, it});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};