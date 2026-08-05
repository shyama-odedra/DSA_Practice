class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = 0;
        int maxArea = 0;

        for (const auto& rect : dimensions) {
            int length = rect[0];
            int width = rect[1];
            int diagSq = length * length + width * width;
            int area = length * width;

            if (diagSq > maxDiagSq) {
                maxDiagSq = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagSq) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};