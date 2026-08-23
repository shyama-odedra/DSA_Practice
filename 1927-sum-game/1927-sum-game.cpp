class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumDiff = 0;
        int qDiff = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                qDiff++;
            } else {
                sumDiff += (num[i] - '0');
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                qDiff--;
            } else {
                sumDiff -= (num[i] - '0');
            }
        }

        return sumDiff * 2 != -qDiff * 9;
    }
};