class Solution {
public:

    bool check(vector<int>& quantities, int size, int n){

        int sum = 0;
        for(int x : quantities){

            sum += (x + size - 1) / size;
            if(sum > n)
                return false;
        }

        return sum <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int l = 1, h = *max_element(quantities.begin(), quantities.end());
        int ans = h;

        while(l <= h){

            int mid = l + (h - l) / 2;
            if(check(quantities, mid, n)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};