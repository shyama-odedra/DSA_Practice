class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        int low = min(minIdx, maxIdx);
        int high = max(minIdx, maxIdx);

        int both_from_front = high + 1;
        int both_from_back = n - low;
        int from_both_sides = (low + 1) + (n - high);

        return min({both_from_front, both_from_back, from_both_sides});
    }
};