class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }

        int k = litters.size();
        int fullMask = (1 << k) - 1;

        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << k, -1)));
        queue<vector<int>> q;

        int initialMask = 0;
        for (int i = 0; i < k; ++i) {
            if (litters[i].first == startX && litters[i].second == startY) {
                initialMask |= (1 << i);
            }
        }

        q.push({startX, startY, initialMask, energy, 0});
        bestEnergy[startX][startY][initialMask] = energy;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr[0];
            int c = curr[1];
            int mask = curr[2];
            int e = curr[3];
            int steps = curr[4];

            if (mask == fullMask) {
                return steps;
            }

            if (e <= 0) continue;

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int nextEnergy = e - 1;
                    int nextMask = mask;

                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }

                    if (classroom[nr][nc] == 'L') {
                        for (int i = 0; i < k; ++i) {
                            if (litters[i].first == nr && litters[i].second == nc) {
                                nextMask |= (1 << i);
                                break;
                            }
                        }
                    }

                    if (nextEnergy > bestEnergy[nr][nc][nextMask]) {
                        bestEnergy[nr][nc][nextMask] = nextEnergy;
                        q.push({nr, nc, nextMask, nextEnergy, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};