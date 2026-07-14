class Solution {
private:
    bool canSplit(const vector<int>& nums, int max_sum, int k) {
        int current_sum = 0;
        int subarrays = 1;
        for (int num : nums) {
            if (current_sum + num > max_sum) {
                subarrays++;
                current_sum = num;
                if (subarrays > k) {
                    return false;
                }
            } else {
                current_sum += num;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        for (int num : nums) {
            low = max(low, num);
            high += num;
        }
        
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};