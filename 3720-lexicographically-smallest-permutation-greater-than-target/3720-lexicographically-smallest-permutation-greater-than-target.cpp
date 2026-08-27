class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string prefix = "";
        int matchLen = 0;
        vector<int> curCount = count;
        
        for (int i = 0; i < n; i++) {
            int ch = target[i] - 'a';
            if (curCount[ch] > 0) {
                prefix += target[i];
                curCount[ch]--;
                matchLen++;
            } else {
                break;
            }
        }
        
        for (int i = matchLen; i >= 0; i--) {
            vector<int> avail = count;
            for (int j = 0; j < i; j++) {
                avail[target[j] - 'a']--;
            }
            
            int startChar = (i < n) ? (target[i] - 'a' + 1) : 26;
            
            for (int c = startChar; c < 26; c++) {
                if (avail[c] > 0) {
                    avail[c]--;
                    
                    string res = target.substr(0, i);
                    res += (char)('a' + c);
                    
                    for (int rem = 0; rem < 26; rem++) {
                        while (avail[rem] > 0) {
                            res += (char)('a' + rem);
                            avail[rem]--;
                        }
                    }
                    return res;
                }
            }
        }
        
        return "";
    }
};