class Solution {
public:
    int distinctSubseqII(string s) {
        long long mod = 1e9 + 7;
        vector<long long> last(26, 0);
        long long currentTotal = 0;

        for (char c : s) {
            int idx = c - 'a';
            long long newSubseqs = (currentTotal + 1) % mod;
            long long diff = (newSubseqs - last[idx] + mod) % mod;
            currentTotal = (currentTotal + diff) % mod;
            last[idx] = newSubseqs;
        }

        return currentTotal;
    }
};