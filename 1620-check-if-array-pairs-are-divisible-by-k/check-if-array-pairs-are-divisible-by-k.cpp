class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        int n = arr.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            while (arr[i] < 0) {
                arr[i] += k;
            }
        }   

        for(int i = 0; i < n; i++){
            int comp = -(arr[i] % k);

            while(comp < 0){
                comp += k;
            }

            if(mp.count(comp)){
                mp[comp]--;

                if(mp[comp] == 0)
                    mp.erase(comp);
            }
            else{
                mp[arr[i] % k]++;
            }
        }

        return mp.empty();
        
    }
};