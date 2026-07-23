#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i);
        }
        
        vector<int> result(n);
        for (int card : deck) {
            result[q.front()] = card;
            q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        
        return result;
    }
};