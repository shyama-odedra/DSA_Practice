class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;
        
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            int remainder = currentSum % k;
            
            if (remainderMap.count(remainder)) {
                if (i - remainderMap[remainder] >= 2) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};