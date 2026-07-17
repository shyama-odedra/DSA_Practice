class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        int moves = 0;
        
        while (left < right) {
            int l = left;
            int r = right;
            
            while (s[l] != s[r]) {
                r--;
            }
            
            if (l == r) {
                swap(s[r], s[r + 1]);
                moves++;
                continue;
            }
            
            while (r < right) {
                swap(s[r], s[r + 1]);
                moves++;
                r++;
            }
            
            left++;
            right--;
        }
        
        return moves;
    }
};