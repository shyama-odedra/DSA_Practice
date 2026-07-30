class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = l * 2;

        while (!enough(weights, days, r)) {
            r *= 2;
        }

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (enough(weights, days, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool enough(vector<int>& weights, int days, int cap) {
        int cur = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w > cap) {
                cur++;
                load = 0;
            }
            load += w;
        }
        return cur <= days;
    }
};