class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_right(n);
        
        min_right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            min_right[i] = min(nums[i], min_right[i + 1]);
        }
        
        int ans = 0;
        int max_left = nums[0];
        
        for (int i = 1; i <= n - 2; i++) {
            if (max_left < nums[i] && nums[i] < min_right[i + 1]) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
            max_left = max(max_left, nums[i]);
        }
        
        return ans;
    }
};