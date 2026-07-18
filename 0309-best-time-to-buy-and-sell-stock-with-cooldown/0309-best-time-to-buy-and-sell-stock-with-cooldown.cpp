class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int buy = -prices[0];
        int sell = 0;
        int cooldown = 0;
        
        for (int i = 1; i < n; i++) {
            int next_buy = max(buy, cooldown - prices[i]);
            int next_sell = max(sell, buy + prices[i]);
            int next_cooldown = max(cooldown, sell);
            
            buy = next_buy;
            sell = next_sell;
            cooldown = next_cooldown;
        }
        
        return max(sell, cooldown);
    }
};