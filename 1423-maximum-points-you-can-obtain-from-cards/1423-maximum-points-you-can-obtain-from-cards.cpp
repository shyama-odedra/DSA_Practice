class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (k == n) return sum;

        int size = n - k;
        int curr = 0;

        for (int i = 0; i < size; ++i) {
            curr += cardPoints[i];
        }

        int mini = curr;

        for (int i = size; i < n; ++i) {
            curr += cardPoints[i] - cardPoints[i - size];
            mini = min(mini, curr);
        }

        return sum - mini;
    }
};