class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> seats;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                seats[row] |= (1 << (col - 2));
            }
        }

        int count = (n - seats.size()) * 2;

        for (const auto& [row, mask] : seats) {
            bool left = (mask & 0b00001111) == 0;
            bool middle = (mask & 0b00111100) == 0;
            bool right = (mask & 0b11110000) == 0;

            if (left && right) {
                count += 2;
            } else if (left || right || middle) {
                count += 1;
            }
        }

        return count;
    }
};