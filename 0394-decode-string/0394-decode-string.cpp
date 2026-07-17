class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string currentString = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                counts.push(k);
                resultStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                string decodedString = resultStack.top();
                resultStack.pop();
                int count = counts.top();
                counts.pop();
                
                for (int i = 0; i < count; i++) {
                    decodedString += currentString;
                }
                currentString = decodedString;
            } else {
                currentString += ch;
            }
        }

        return currentString;
    }
};