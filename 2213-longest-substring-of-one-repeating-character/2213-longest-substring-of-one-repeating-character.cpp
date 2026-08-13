class Solution {
    struct Node {
        char leftChar;
        char rightChar;
        int len;
        int maxPrefix;
        int maxSuffix;
        int maxLen;
    };

    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        res.len = left.len + right.len;

        res.maxPrefix = left.maxPrefix;
        if (left.maxPrefix == left.len && left.rightChar == right.leftChar) {
            res.maxPrefix = left.len + right.maxPrefix;
        }

        res.maxSuffix = right.maxSuffix;
        if (right.maxSuffix == right.len && left.rightChar == right.leftChar) {
            res.maxSuffix = right.len + left.maxSuffix;
        }

        res.maxLen = max(left.maxLen, right.maxLen);
        if (left.rightChar == right.leftChar) {
            res.maxLen = max(res.maxLen, left.maxSuffix + right.maxPrefix);
        }

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {val, val, 1, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].maxLen;
        }

        return ans;
    }
};