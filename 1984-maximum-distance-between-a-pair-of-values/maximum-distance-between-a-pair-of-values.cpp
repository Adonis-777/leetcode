class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        int i = 0;

        int maxLen = 0;
        for(int j = 0; j < m; j++){

            while(i < n && nums1[i] > nums2[j])
                i++;
            
            while(j < m && j < i)
                j++;

            if(i == n)
                break;
            int len = j - i;
            maxLen = max(maxLen, len);

        }

        return maxLen;
    
    }
};