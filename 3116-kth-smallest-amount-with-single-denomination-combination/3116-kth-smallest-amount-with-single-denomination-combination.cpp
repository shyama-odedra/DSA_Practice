class Solution {
public:
    long long countAmounts(long long x, const vector<int>& coins) {
        long long count = 0;
        int n = coins.size();
        
        for (int i = 1; i < (1 << n); ++i) {
            long long currentLcm = 1;
            int setBits = 0;
            bool overflow = false;
            
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    setBits++;
                    long long g = std::gcd(currentLcm, (long long)coins[j]);
                    currentLcm = (currentLcm / g) * coins[j];
                    if (currentLcm > x) {
                        overflow = true;
                        break;
                    }
                }
            }
            
            if (overflow) continue;
            
            if (setBits % 2 == 1) {
                count += x / currentLcm;
            } else {
                count -= x / currentLcm;
            }
        }
        
        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countAmounts(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};