class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [](const vector<int>&a, const vector<int>& b){
            return a[1] < b[1];});
        

        int count = 1;
        int curr_end = points[0][1];

        for(auto& p : points){
            if(p[0] > curr_end){
                count++;
                curr_end = p[1];
            }
        }

        return count;
    }
};