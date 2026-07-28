class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long c=0;
        int n=nums.size();

        for(int i=0; i<n; i++){
            int min= lower-nums[i];
            int max= upper-nums[i];

            auto left = lower_bound(nums.begin() + i + 1, nums.end(), min);
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), max);

            c += (right-left);
        }
        return c;
    }
};