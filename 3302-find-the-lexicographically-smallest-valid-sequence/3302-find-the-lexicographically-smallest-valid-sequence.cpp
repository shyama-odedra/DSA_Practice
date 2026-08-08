class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> last(m, -1);
        
        int ptr = m - 1;
        for (int i = n - 1; i >= 0 && ptr >= 0; i--) {
            if (word1[i] == word2[ptr]) {
                last[ptr] = i;
                ptr--;
            }
        }

        vector<int> ans;
        bool changed = false;
        ptr = 0;

        for (int i = 0; i < n && ptr < m; i++) {
            if (word1[i] == word2[ptr]) {
                ans.push_back(i);
                ptr++;
            } else {
                bool can_change = false;
                if (!changed) {
                    if (ptr == m - 1 || last[ptr + 1] > i) {
                        can_change = true;
                    }
                }
                
                if (can_change) {
                    ans.push_back(i);
                    ptr++;
                    changed = true;
                }
            }
        }

        if (ans.size() == m) return ans;
        return {};
    }
};