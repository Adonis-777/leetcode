/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        int l = 1, h = n;
        int ans;

        while(l <= h){
            
            int mid = l + (h - l) / 2;
            if(guess(mid) == -1){

                // my guess is higher than number picked
                h = mid - 1;
            }
            else if(guess(mid) == 1){
                // number that i have picked is lower than picked number
                l = mid + 1;
            }
            else{
                ans = mid;
                break;
            }
        }

        return ans;
        
    }
};