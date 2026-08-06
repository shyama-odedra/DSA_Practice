class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minElement(vector<int>& nums) {
        int minVal = INT_MAX;
        for (int num : nums) {
            minVal = min(minVal, getDigitSum(num));
        }
        return minVal;
    }
};