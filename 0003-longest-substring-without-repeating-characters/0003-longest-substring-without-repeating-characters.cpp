class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (lastSeen[s[i]] >= start) {
                start = lastSeen[s[i]] + 1;
            }
            lastSeen[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};