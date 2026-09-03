class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        int min_odd = 2e9;

        for (int x : nums1) {
            min_val = min(min_val, x);
            if (x % 2 != 0) {
                min_odd = min(min_odd, x);
            }
        }

        if (min_val % 2 != 0) {
            return true;
        }

        if (min_odd == 2e9) {
            return true;
        }

        for (int x : nums1) {
            if (x % 2 != 0 && x < min_val) {
                return false;
            }
        }

        for (int x : nums1) {
            if (x % 2 == 0) {
                if (x - min_odd < 1) {
                    return false;
                }
            }
        }

        return true;
    }
};