class Solution {
public:
    int pivotIndex(vector<int>& a) {

        // prefix[i - 1] == suffix[i + 1] ==> return i
        int n = a.size();
        vector<int> pref(n, 0), suff(n, 0);

        if(n == 1)
            return 0;

        pref[0] = a[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i - 1] + a[i];
        }

        suff[n - 1] = a[n - 1];
        for(int i = (n - 2); i >= 0; i--){
            suff[i] = suff[i + 1] + a[i];
        }

        for(int i = 0; i < n; i++){

            if(i == 0){
                if(suff[1] == 0)
                    return 0;
            }
            else if(i == (n - 1)){
                if(pref[i - 1] == 0)    
                    return i;
            }

            else if(i > 0 && i < (n - 1)){

                if(pref[i - 1] == suff[i + 1])
                    return i;
            }
        }

        return -1;

        
    }
};