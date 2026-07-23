class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totalSeconds = 0;
        int targetTickets = tickets[k];

        for (int i = 0; i < tickets.size(); ++i) {
            if (i <= k) {
                totalSeconds += min(tickets[i], targetTickets);
            } else {
                totalSeconds += min(tickets[i], targetTickets - 1);
            }
        }

        return totalSeconds;
    }
};