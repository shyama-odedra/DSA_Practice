class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> s;
        
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.back()] > nums[i]) {
                s.push_back(i);
            }
        }
        
        int maxWidth = 0;
        
        for (int j = n - 1; j >= 0; --j) {
            while (!s.empty() && nums[s.back()] <= nums[j]) {
                maxWidth = max(maxWidth, j - s.back());
                s.pop_back();
            }
        }
        
        return maxWidth;
    }
};