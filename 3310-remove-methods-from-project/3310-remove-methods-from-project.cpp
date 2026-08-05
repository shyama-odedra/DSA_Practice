class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> suspicious(n, false);
        vector<int> q;
        q.push_back(k);
        suspicious[k] = true;

        int head = 0;
        while (head < (int)q.size()) {
            int u = q[head++];
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push_back(v);
                }
            }
        }

        bool can_remove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!suspicious[u] && suspicious[v]) {
                can_remove = false;
                break;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!can_remove || !suspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};