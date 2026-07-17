class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = 0;
        for (int c : candies) {
            high = max(high, (long long)c);
        }
        
        int ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long piles = 0;
            
            for (int c : candies) {
                piles += c / mid;
            }
            
            if (piles >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};