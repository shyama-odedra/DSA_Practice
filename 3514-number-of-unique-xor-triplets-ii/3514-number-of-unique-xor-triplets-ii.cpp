class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }

        int maskLimit = 1;
        while (maskLimit <= maxVal) {
            maskLimit <<= 1;
        }

        vector<bool> hasSingle(maskLimit, false);
        for (int x : nums) {
            hasSingle[x] = true;
        }

        vector<bool> hasPair(maskLimit, false);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                hasPair[nums[i] ^ nums[j]] = true;
            }
        }

        vector<bool> hasTriplet(maskLimit, false);
        for (int i = 0; i < maskLimit; ++i) {
            if (!hasSingle[i]) continue;
            for (int j = 0; j < maskLimit; ++j) {
                if (hasPair[j]) {
                    hasTriplet[i ^ j] = true;
                }
            }
        }

        int uniqueCount = 0;
        for (int i = 0; i < maskLimit; ++i) {
            if (hasTriplet[i]) {
                uniqueCount++;
            }
        }

        return uniqueCount;
    }
};