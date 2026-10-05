class Solution {
public:
    bool increasingTriplet(vector<int>& a) {

        int n = a.size();
        int x = INT_MAX, y = INT_MAX;

        for(int i : a){
            if(i <= x) x = i;
            else if(i <= y) y = i;
            else return true;
        }

        return false;
        
    }
};