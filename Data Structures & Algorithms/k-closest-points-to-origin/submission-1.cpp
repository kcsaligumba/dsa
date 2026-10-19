class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>> pq;
        int dist;
        for (const vector<int> & point : points) {
            dist = point[0] * point[0] + point[1] * point[1];
            pq.push({dist, {point[0], point[1]}});
            if (pq.size() > k) pq.pop();
        }
        while (!pq.empty()) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};
