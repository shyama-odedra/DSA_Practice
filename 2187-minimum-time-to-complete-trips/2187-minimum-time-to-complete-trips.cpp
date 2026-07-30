class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long min_time = time[0];
        for (int t : time) {
            min_time = min(min_time, (long long)t);
        }
        long long high = min_time * totalTrips;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long trips = 0;
            for (int t : time) {
                trips += mid / t;
            }

            if (trips >= totalTrips) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};