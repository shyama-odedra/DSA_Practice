class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }
        
        vector<long long> count(maxVal + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        vector<long long> gcdCount(maxVal + 1, 0);
        for (int i = maxVal; i >= 1; --i) {
            long long multiples = 0;
            for (int j = i; j <= maxVal; j += i) {
                multiples += count[j];
            }
            
            long long totalPairs = (multiples * (multiples - 1)) / 2;
            for (int j = 2 * i; j <= maxVal; j += i) {
                totalPairs -= gcdCount[j];
            }
            gcdCount[i] = totalPairs;
        }
        
        vector<long long> prefixSum(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; ++i) {
            prefixSum[i] = prefixSum[i - 1] + gcdCount[i];
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            int idx = upper_bound(prefixSum.begin(), prefixSum.end(), q) - prefixSum.begin();
            ans.push_back(idx);
        }
        
        return ans;
    }
};