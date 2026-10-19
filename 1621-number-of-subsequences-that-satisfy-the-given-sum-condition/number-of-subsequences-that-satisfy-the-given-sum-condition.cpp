class Solution {
public:

    #define fl(i,l, h) for(int i = l; i < h; i++)
    const int check = 1000000007;
    typedef long long ll;

    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> pre;
        pre.push_back(1);

        for(int i = 1; i <= n; i++){
            int get = pre.back();
            int push = (get * 2) % check;
            pre.push_back(push);
        }

        int i = 0, j = n - 1;
        int count = 0;

        while(i <= j){

            int sum = nums[i] + nums[j];
            if(sum > target) j--;
            else{

                count = (count + pre[j - i]) % check;
                i++;

            }
        }

        return count;
        
    }
};