class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }
        
        vector<int> result;
        
        for (int i = 100; i <= 998; i += 2) {
            int d1 = i / 100;
            int d2 = (i / 10) % 10;
            int d3 = i % 10;
            
            count[d1]--;
            count[d2]--;
            count[d3]--;
            
            if (count[d1] >= 0 && count[d2] >= 0 && count[d3] >= 0) {
                result.push_back(i);
            }
            
            count[d1]++;
            count[d2]++;
            count[d3]++;
        }
        
        return result;
    }
};