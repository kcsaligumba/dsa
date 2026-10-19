class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(const int & s : stones) {
            pq.push(s);
        }
        int first, second;
        while (pq.size() > 1) {
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();
            if (first == second) continue;
            if (first < second) pq.push(second - first);
            else pq.push(first - second);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
