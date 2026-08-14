class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        int m = 0;
        int l = 0;

        for(int r=0; r<s.length(); ++r){
            freq[s[r] -'a']++;

            while(freq[s[r]- 'a']>2){
                freq[s[l]- 'a']--;
                l++;
            }
            m = max(m, r - l+1); 
        }
        return m;
    }
};