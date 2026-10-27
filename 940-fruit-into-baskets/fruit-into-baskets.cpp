class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        map<int, int> mp;
        int j = 0;
        int n = fruits.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++){

            mp[fruits[i]]++;

            while(mp.size() > 2){
                mp[fruits[j]]--;

                if(mp[fruits[j]] == 0)
                    mp.erase(fruits[j]);

                j++;
            }

            int len = i - j + 1;
            maxLen = max(maxLen, len);

        }

        return maxLen;
        
    }
};