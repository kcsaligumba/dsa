class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indeg(n);
        for (const auto& edge : edges) {
            indeg[edge[1]] = true;
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == false) {
                res.push_back(i);
            }
        }

        return res;
    }
};
