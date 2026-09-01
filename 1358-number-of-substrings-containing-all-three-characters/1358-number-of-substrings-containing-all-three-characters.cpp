class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> counts;
        int left = 0, total = 0;

        for (int right = 0; right < s.length(); ++right) {
            counts[s[right]]++;

            while (counts.size() == 3) {
                total += s.length() - right;

                counts[s[left]]--;
                if (counts[s[left]] == 0) {
                    counts.erase(s[left]);
                }
                left++;
            }
        }

        return total;
    }
};