class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> count;
        for (int num : arr1) {
            count[num]++;
        }
        
        vector<int> result;
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        
        for (auto& pair : count) {
            while (pair.second > 0) {
                result.push_back(pair.first);
                pair.second--;
            }
        }
        
        return result;
    }
};