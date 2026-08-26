class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        unordered_map<char, int> wordMapCount; // aggregated frequency count of words
        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }

        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> currentMap;

            while (right + wordLen <= sLen) {
                string w = s.substr(right, wordLen);
                right += wordLen;

                if (wordMap.count(w)) {
                    currentMap[w]++;
                    count++;

                    while (currentMap[w] > wordMap[w]) {
                        string leftWord = s.substr(left, wordLen);
                        currentMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    currentMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};