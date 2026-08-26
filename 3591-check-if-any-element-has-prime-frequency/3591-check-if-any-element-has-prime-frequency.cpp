class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& pair : freq) {
            int f = pair.second;
            if (f <= 1) continue;
            bool isPrime = true;
            for (int i = 2; i * i <= f; i++) {
                if (f % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) return true;
        }
        return false;
    }
};