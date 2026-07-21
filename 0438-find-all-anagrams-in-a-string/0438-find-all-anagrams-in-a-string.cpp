class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int ns = s.length(), np = p.length();
        if (ns < np) return result;

        vector<int> p_count(26, 0), s_count(26, 0);
        for (int i = 0; i < np; ++i) {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++;
        }

        if (p_count == s_count) result.push_back(0);

        for (int i = np; i < ns; ++i) {
            s_count[s[i] - 'a']++;
            s_count[s[i - np] - 'a']--;
            if (p_count == s_count) {
                result.push_back(i - np + 1);
            }
        }

        return result;
    }
};