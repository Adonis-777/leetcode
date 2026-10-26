class Solution {
public:

    bool check(vector<int>& pos, int force, int balls){

        int count = 1;
        int last = pos[0];
        int n = pos.size();

        for(int i = 1; i < n; i++){
            if(pos[i] - last >= force){
                last = pos[i];
                count++;
            }
            if(count >= balls)
                return true;
        }

        return count >= balls;
    }
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());
        // what could be minimum force? --> position[1] - position[0]
        // maximum force --> position[n - 1] - position[0]
        int n = position.size();
        int l = 0, h = position[n - 1] - position[0];
        int ans = h;

        while(l <= h){
            int mid = l + (h - l) / 2;

            if(check(position, mid, m)){
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