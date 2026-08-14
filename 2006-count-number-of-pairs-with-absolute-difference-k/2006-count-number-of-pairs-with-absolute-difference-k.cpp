class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;

        for (int num : nums) {
            if (freq.count(num - k)) {
                count += freq[num - k];
            }
            if (freq.count(num + k)) {
                count += freq[num + k];
            }
            freq[num]++;
        }

        return count;
    }
};