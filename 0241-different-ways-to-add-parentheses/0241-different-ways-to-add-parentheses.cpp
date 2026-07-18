class Solution {
private:
    unordered_map<string, vector<int>> memo;

public:
    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) {
            return memo[expression];
        }
        
        vector<int> res;
        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.push_back(l + r);
                        else if (c == '-') res.push_back(l - r);
                        else if (c == '*') res.push_back(l * r);
                    }
                }
            }
        }
        
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        
        memo[expression] = res;
        return res;
    }
};