class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int req) {

        int n = flowerbed.size();
        int free_spots = 0;

        if (req == 0)
            return true;

        for (int i = 0; i < n; i++) {

            if (flowerbed[i] == 1)
                continue;

            bool left = (i == 0 || flowerbed[i - 1] == 0);
            bool right = (i == n - 1 || flowerbed[i + 1] == 0);

            if (left && right) {
                free_spots++;
                flowerbed[i] = 1;

                if (free_spots >= req)
                    return true;

                i++; // skip next position
            }
        }

        return false;
    }
};