class Solution {
public:


    vector<int> NextSmaller(vector<int>&heights){

        stack<int> s;
        int n = heights.size();
        vector<int> ns(n);
        for(int i = (n - 1); i >= 0; i--){

            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            if(s.empty()){
                ns[i] = n;
            }
            else{
                ns[i] = s.top();
            }

            s.push(i);
        }

        return ns;
    }

    vector<int> PreviousSmaller(vector<int>&heights){

        stack<int> s;
        int n = heights.size();
        vector<int> ps(n);

        for(int i = 0; i < n; i++){

            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            if(s.empty())
                ps[i] = -1;
            else
                ps[i] = s.top();
            s.push(i);
        }

        return ps;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int max_area = 0;

        vector<int> ps = PreviousSmaller(heights);
        vector<int> ns = NextSmaller(heights);

        for(int i = 0; i < n; i++){

            int width = (ns[i] - ps[i] - 1);
            int height = heights[i];

            int curr_area = width * height;

            max_area = max(max_area, curr_area);
        }

        return max_area;
    }
};