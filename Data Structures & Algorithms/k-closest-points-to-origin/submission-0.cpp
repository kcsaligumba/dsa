class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double, vector<int>>> pq;
        double dist;
        for (const vector<int> & point : points) {
            dist = sqrt(point[0] * point[0] + point[1] * point[1]);
            pq.push({dist, point});
            if (pq.size() > k) pq.pop();
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
