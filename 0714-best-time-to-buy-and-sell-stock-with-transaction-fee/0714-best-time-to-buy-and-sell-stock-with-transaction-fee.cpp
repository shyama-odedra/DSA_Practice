class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int buy = -prices[0] - fee;
        int sell = 0;
        
        for (int i = 1; i < n; i++) {
            buy = max(buy, sell - prices[i] - fee);
            sell = max(sell, buy + prices[i]);
        }
        
        return sell;
    }
};