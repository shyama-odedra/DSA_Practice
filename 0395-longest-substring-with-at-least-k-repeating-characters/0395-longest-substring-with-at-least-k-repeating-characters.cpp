class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n == 0 || k > n) return 0;
        if (k <= 1) return n;

        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        int split = 0;
        while (split < n && counts[s[split]] >= k) {
            split++;
        }

        if (split == n) return n;

        int left = longestSubstring(s.substr(0, split), k);
        while (split < n && counts[s[split]] < k) {
            split++;
        }
        int right = longestSubstring(s.substr(split), k);

        return max(left, right);
    }
};