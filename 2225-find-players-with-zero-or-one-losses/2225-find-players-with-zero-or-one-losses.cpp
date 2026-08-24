class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lossCount;
        
        for (const auto& match : matches) {
            int winner = match[0];
            int loser = match[1];
            
            if (lossCount.find(winner) == lossCount.end()) {
                lossCount[winner] = 0;
            }
            lossCount[loser]++;
        }
        
        vector<int> zeroLoss;
        vector<int> oneLoss;
        
        for (const auto& [player, count] : lossCount) {
            if (count == 0) {
                zeroLoss.push_back(player);
            } else if (count == 1) {
                oneLoss.push_back(player);
            }
        }
        
        return {zeroLoss, oneLoss};
    }
};