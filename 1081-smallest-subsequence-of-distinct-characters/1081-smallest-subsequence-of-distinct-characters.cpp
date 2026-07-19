class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIdx[s[i] - 'a'] = i;
        }
        
        vector<bool> seen(26, false);
        string result = "";
        
        for (int i = 0; i < s.length(); i++) {
            int curr = s[i] - 'a';
            if (seen[curr]) continue;
            
            while (!result.empty() && result.back() > s[i] && lastIdx[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(s[i]);
            seen[curr] = true;
        }
        
        return result;
    }
};