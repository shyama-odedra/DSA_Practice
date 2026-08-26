class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> freq;
        for (char c : num) {
            freq[c - '0']++;
        }
        for (int i = 0; i < num.length(); i++) {
            if (freq[i] != (num[i] - '0')) {
                return false;
            }
        }
        return true;
    }
};