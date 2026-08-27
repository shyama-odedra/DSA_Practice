class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty()|| t.empty()|| s.length()< t.length()) {
            return "";
        }

        vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }

        int c = t.length();
        int left=0;
        int min=INT_MAX;
        int start=0;

        for(int right=0; right<s.length(); right++){
            if(map[s[right]]-- >0){
                c--;
            }

            while(c==0){
                if(right-left+1 < min){
                    min = right-left+ 1;
                    start=left;
                }

                if(map[s[left++]]++ ==0){
                    c++;
                }
            }
        }
        return min== INT_MAX ? "" : s.substr(start, min);
    }
};