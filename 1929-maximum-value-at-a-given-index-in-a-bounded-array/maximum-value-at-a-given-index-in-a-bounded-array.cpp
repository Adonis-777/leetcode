class Solution {
public:

    bool check(int n, int index, int val, int maxSum){

        // a[index] = val
        // check right first i -> index + 1 till n - 1
        int i = index + 1, curr_val = val - 1;
        long long sum = 0;
        while(i < n){
            if(curr_val == 1){
                break;
            }
            sum += (long long)curr_val;
            if(sum > maxSum)
                return false;
            curr_val--;
            i++;
        }

        sum += (n - i);
        i = index - 1;
        curr_val = val - 1;
        while(i >= 0){
            if(curr_val == 1){
                break;
            }
            sum += (long long)curr_val;
            
            if(sum > maxSum)
                return false;
            curr_val--;
            i--;
        }

        sum += (i + 1);
        sum += val;

        return sum <= maxSum;

    }
    int maxValue(int n, int index, int maxSum) {

        int l = 1, h = maxSum;
        int ans;
        while(l <= h){
            int mid = l + (h - l) / 2;

            if(check(n, index, mid, maxSum)){
                ans = mid;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};