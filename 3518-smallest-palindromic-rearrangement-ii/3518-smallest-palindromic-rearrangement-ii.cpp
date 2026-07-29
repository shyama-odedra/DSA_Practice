class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> fullFreq(26, 0);
        for (char c : s) {
            fullFreq[c - 'a']++;
        }

        vector<long long> freq(26, 0);
        char midChar = '\0';
        int halfLen = n / 2;

        for (int i = 0; i < 26; i++) {
            freq[i] = fullFreq[i] / 2;
            if (fullFreq[i] % 2 != 0) {
                midChar = 'a' + i;
            }
        }

        auto countPermutations = [&](vector<long long>& f, int remLen, long long limit) -> long long {
            long long res = 1;
            int currentLen = 0;

            for (int i = 0; i < 26; i++) {
                long long count = f[i];
                for (int j = 1; j <= count; j++) {
                    currentLen++;
                    res = (res * currentLen) / j;
                    if (res > limit) {
                        return limit + 1;
                    }
                }
            }
            return res;
        };

        long long totalPerms = countPermutations(freq, halfLen, k);
        if (totalPerms < k) {
            return "";
        }

        string half = "";
        long long currentK = k;

        for (int pos = 0; pos < halfLen; pos++) {
            int remLen = halfLen - 1 - pos;

            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0) continue;

                freq[c]--;
                long long perms = countPermutations(freq, remLen, currentK);

                if (currentK <= perms) {
                    half += (char)('a' + c);
                    break;
                } else {
                    currentK -= perms;
                    freq[c]++;
                }
            }
        }

        string result = half;
        if (n % 2 != 0) {
            result += midChar;
        }
        string rightHalf = half;
        reverse(rightHalf.begin(), rightHalf.end());
        result += rightHalf;

        return result;
    }
};