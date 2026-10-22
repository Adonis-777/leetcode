class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int n = arr.size();
        int l = 1, h = n - 2;
        int ans;

        while(l <= h){
            int mid = l + (h - l) / 2;

            
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
                // we are at the summit, return this answer
                    ans = mid;
                    break;
            }

            if(arr[mid] > arr[mid + 1]){
                // decreasing slant --> we are on the decling edge that is right side of the mountain
                h = mid - 1;
            }
            else if(arr[mid] > arr[mid - 1]){
                // increasing slant --> we are on the inclineing edge that is the left side of the mountain
                l = mid + 1;
            }
            
        
        }

        return ans;
        
    }
};