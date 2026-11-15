class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<pair<int,int>> left, right;
        int n = asteroids.size();

        for(int i = 0; i < n; i++){
            int x = asteroids[i];

            if(x > 0){

                // right
                right.push({i, x});
            }

            else{

                // left
                while(!right.empty() && abs(x) > right.top().second){
                    right.pop();
                }
                if(!right.empty() && abs(x) == right.top().second){
                    
                    // both will go
                    right.pop();
                    continue;
                }

                if(right.empty()){
                    // all obstacles crossed

                    left.push({i, x});
                }
            }
        }

        vector<pair<int, int>> temp;
        while(!left.empty()){
            pair<int, int> t = left.top();
            left.pop();
            temp.push_back(t);
        }

        while(!right.empty()){
            pair<int, int> t = right.top();
            right.pop();
            temp.push_back(t);
        }

        sort(temp.begin(), temp.end());
        vector<int> ans;
        for(auto it : temp){
            ans.push_back(it.second);
        }

        return ans;
        
    }
};