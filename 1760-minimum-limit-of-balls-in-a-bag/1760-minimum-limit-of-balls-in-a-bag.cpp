class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = 0;
        for (int num : nums) {
            high = max(high, num);
        }
        
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;
            
            for (int num : nums) {
                if (num > mid) {
                    operations += (num - 1) / mid;
                }
            }
            
            if (operations <= maxOperations) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};