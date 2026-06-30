class Solution {
private:
    const std::vector<std::string> keypad = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        const std::string& letters = keypad[digit];

        for (char letter : letters) {
            current.push_back(letter);             
            backtrack(digits, index + 1, current, result); 
            current.pop_back();                
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        
        if (digits.empty()) {
            return result;
        }

        std::string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};
