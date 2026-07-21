class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') {
                total_ones++;
            }
        }

        string t = "1" + s + "1";
        vector<pair<char, int>> segs;
        for (char c : t) {
            if (segs.empty() || segs.back().first != c) {
                segs.push_back({c, 1});
            } else {
                segs.back().second++;
            }
        }

        int max_gain = 0;
        for (int i = 1; i < (int)segs.size() - 1; ++i) {
            if (segs[i].first == '1' && segs[i - 1].first == '0' && segs[i + 1].first == '0') {
                max_gain = max(max_gain, segs[i - 1].second + segs[i + 1].second);
            }
        }

        return total_ones + max_gain;
    }
};