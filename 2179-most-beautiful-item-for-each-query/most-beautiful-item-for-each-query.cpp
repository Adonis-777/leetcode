class Solution {
public:

    int helper(int budget, vector<vector<int>>& items){

        int bestProduct = 0;
        int l = 0, h = items.size() - 1;

        while(l <= h){

            int mid = l + (h - l) / 2;
            if(items[mid][0] > budget){
                h = mid - 1;
            }
            else{
                bestProduct = max(bestProduct, items[mid][1]);
                l = mid + 1;
            }
        }

        return bestProduct;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        // sort items based on prices --> items[i][0]
        sort(items.begin(), items.end());

        for(int i = 1; i < items.size(); i++){
            items[i][1] = max(items[i][1], items[i-1][1]); //beauty stores the maximum beauty among all items up to that price.
        }

        // traverse queries array and for each query price run a binary search on items array..
        // if items[mid][0] > query[j] --> h = mid - 1;
        // else: ans = max(ans, items[mid][1]) and l = mid + 1 (for a better beauty product)

        int n = queries.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = helper(queries[i], items);
        }
        
        return ans;
    }
};