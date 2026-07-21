class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total_sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (k == n) return total_sum;

        int window_size = n - k;
        int current_window_sum = 0;

        for (int i = 0; i < window_size; ++i) {
            current_window_sum += cardPoints[i];
        }

        int min_window_sum = current_window_sum;

        for (int i = window_size; i < n; ++i) {
            current_window_sum += cardPoints[i] - cardPoints[i - window_size];
            min_window_sum = min(min_window_sum, current_window_sum);
        }

        return total_sum - min_window_sum;
    }
};