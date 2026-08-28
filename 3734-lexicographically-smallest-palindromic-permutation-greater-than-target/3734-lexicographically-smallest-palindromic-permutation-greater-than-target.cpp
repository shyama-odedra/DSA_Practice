class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        int oddCount = 0;
        char midChar = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                oddCount++;
                midChar = 'a' + i;
            }
        }
        
        if ((n % 2 == 0 && oddCount > 0) || (n % 2 != 0 && oddCount != 1)) {
            return "";
        }
        
        vector<int> halfCount(26, 0);
        for (int i = 0; i < 26; i++) {
            halfCount[i] = count[i] / 2;
        }
        
        int halfLen = n / 2;
        
        auto constructPalindrome = [&](const string& halfPrefix) -> string {
            string res = halfPrefix;
            vector<int> rem = halfCount;
            for (char c : halfPrefix) {
                rem[c - 'a']--;
            }
            for (int i = 0; i < 26; i++) {
                if (rem[i] < 0) return "";
                res.append(rem[i], 'a' + i);
            }
            string full = res;
            if (n % 2 != 0) {
                full += midChar;
            }
            string rightHalf = res;
            reverse(rightHalf.begin(), rightHalf.end());
            full += rightHalf;
            return full;
        };
        
        for (int L = halfLen; L >= 0; L--) {
            string prefix = target.substr(0, L);
            vector<int> rem = halfCount;
            bool possible = true;
            for (char c : prefix) {
                if (--rem[c - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;
            
            if (L == halfLen) {
                string cand = constructPalindrome(prefix);
                if (cand > target) return cand;
                continue;
            }
            
            char targetChar = target[L];
            for (int ch = targetChar - 'a' + 1; ch < 26; ch++) {
                if (rem[ch] > 0) {
                    string nextPrefix = prefix;
                    nextPrefix += (char)('a' + ch);
                    string cand = constructPalindrome(nextPrefix);
                    if (cand > target) return cand;
                }
            }
        }
        
        return "";
    }
};