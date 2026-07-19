class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long mod = 1e9 + 7;
        
        vector<long long> psum(n + 1, 0), pval(n + 1, 0), pow10(n + 1, 1);
        vector<int> nz(n + 1, 0), next_nz(n + 1, n), prev_nz(n, -1);
        
        for (int i = 0; i < n; ++i) {
            pow10[i + 1] = (pow10[i] * 10) % mod;
            int d = s[i] - '0';
            psum[i + 1] = psum[i] + d;
            pval[i + 1] = d ? (pval[i] * 10 + d) % mod : pval[i];
            nz[i + 1] = nz[i] + (d > 0);
        }
        
        for (int i = n - 1, l1 = n, l2 = -1; i >= 0; --i) {
            if (s[i] != '0') l1 = i;
            next_nz[i] = l1;
            int idx = n - 1 - i;
            if (s[idx] != '0') l2 = idx;
            prev_nz[idx] = l2;
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int first = next_nz[q[0]], last = prev_nz[q[1]];
            if (first > last) {
                ans.push_back(0);
            } else {
                long long sum = psum[last + 1] - psum[first];
                long long rem = (pval[first] * pow10[nz[last + 1] - nz[first]]) % mod;
                long long x = (pval[last + 1] - rem + mod) % mod;
                ans.push_back((x * sum) % mod);
            }
        }
        
        return ans;
    }
};