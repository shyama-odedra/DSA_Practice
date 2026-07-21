class Solution {
public:
    int binaryGap(int n) {
        int max_dist = 0;
        int last_pos = -1;
        int current_pos = 0;

        while (n > 0) {
            if (n & 1) {
                if (last_pos != -1) {
                    max_dist = max(max_dist, current_pos - last_pos);
                }
                last_pos = current_pos;
            }
            n >>= 1;
            current_pos++;
        }

        return max_dist;
    }
};