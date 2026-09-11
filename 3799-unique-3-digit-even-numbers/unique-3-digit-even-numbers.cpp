class Solution {
public:
    int totalNumbers(vector<int>& digits) {
    int cnt[10] = {0};
    for (int d : digits) cnt[d]++;

    int ans = 0;
    for (int h = 1; h <= 9; h++) {          // hundreds: no leading zero
        if (cnt[h] == 0) continue;
        cnt[h]--;
        for (int t = 0; t <= 9; t++) {      // tens: any digit
            if (cnt[t] == 0) continue;
            cnt[t]--;
            for (int u = 0; u <= 8; u += 2) // units: must be even
                if (cnt[u] > 0) ans++;
            cnt[t]++;
        }
        cnt[h]++;
    }
    return ans;
}
};