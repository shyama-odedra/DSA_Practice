class Solution {
private:
    bool canPlace(const vector<int>& position, int distance, int m) {
        int count = 1;
        int lastPos = position[0];
        for (size_t i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= distance) {
                count++;
                lastPos = position[i];
                if (count >= m) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position[0];
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(position, mid, m)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};