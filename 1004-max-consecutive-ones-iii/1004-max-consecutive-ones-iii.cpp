class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefZeros(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefZeros[i + 1] = prefZeros[i] + (nums[i] == 0 ? 1 : 0);
        }
        
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int low = i, high = n - 1, bestJ = i - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int zeroCount = prefZeros[mid + 1] - prefZeros[i];
                if (zeroCount <= k) {
                    bestJ = mid;
                    low = mid + 1; 
                } else {
                    high = mid - 1;
                }
            }
            maxLen = max(maxLen, bestJ - i + 1);
        }
        return maxLen;
    }
};