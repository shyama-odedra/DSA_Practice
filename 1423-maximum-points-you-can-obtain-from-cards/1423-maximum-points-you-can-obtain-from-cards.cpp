class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        for(int i =0;i<k;i++) {
            lsum += cardPoints[i];
        }
        int maxsum = lsum;
        int rightind = n-1;
        for(int i =k-1;i>=0;i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rightind];
            rightind--;
            maxsum = max(maxsum, (lsum+rsum));
        }
        return maxsum;
    }
};