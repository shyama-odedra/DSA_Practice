class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];
        
        if (n == 2) return std::min(first, second);
        
        for (int i = 2; i < n; ++i) {
            int current = cost[i] + std::min(first, second);
            first = second;
            second = current;
        }
        
        return std::min(first, second);
    }
};