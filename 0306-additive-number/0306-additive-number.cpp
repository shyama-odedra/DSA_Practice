class Solution {
private:
    string stringAdd(string num1, string num2) {
        string result = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool isValid(string n1, string n2, int start, const string& num) {
        while (start < num.length()) {
            string sum = stringAdd(n1, n2);
            if (num.compare(start, sum.length(), sum) != 0) {
                return false;
            }
            start += sum.length();
            n1 = n2;
            n2 = sum;
        }
        return true;
    }

public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for (int i = 1; i <= n / 2; ++i) {
            if (num[0] == '0' && i > 1) break;
            string n1 = num.substr(0, i);

            for (int j = 1; max(i, j) <= n - i - j; ++j) {
                if (num[i] == '0' && j > 1) break;
                string n2 = num.substr(i, j);

                if (isValid(n1, n2, i + j, num)) {
                    return true;
                }
            }
        }
        return false;
    }
};