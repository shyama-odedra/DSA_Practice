class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        
        string half = s.substr(0, n / 2);
        sort(half.begin(), half.end());
        
        string mid = "";
        if (n % 2 != 0) {
            mid = s[n / 2];
        }
        
        string second_half = half;
        reverse(second_half.begin(), second_half.end());
        
        return half + mid + second_half;
    }
};