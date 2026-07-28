class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int c=0;
        int left=0;
        int right= nums.size()-1;

        while(left<right){
            if(nums[left] + nums[right] < target){
                c += (right-left);
                left++;
            } else {
                right--;
            }
        }
        return c;
    }
};