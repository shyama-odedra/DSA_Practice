class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        long long total_sum = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            total_sum = (total_sum + (long long)arr[i] * left[i] * right[i]) % mod;
        }

        return total_sum;   
    }
};