class Solution {
public:
    long long numberOfWays(string s) {
        long long totalZeros = 0, totalOnes = 0;
        for (char c : s) {
            if (c == '0') totalZeros++;
            else totalOnes++;
        }

        long long leftZeros = 0, leftOnes = 0;
        long long ans = 0;

        for (char c : s) {
            if (c == '0') {
                long long rightOnes = totalOnes - leftOnes;
                ans += leftOnes * rightOnes;
                leftZeros++;
            } else {
                long long rightZeros = totalZeros - leftZeros;
                ans += leftZeros * rightZeros;
                leftOnes++;
            }
        }

        return ans;
    }
};