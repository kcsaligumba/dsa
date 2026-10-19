class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskFrequency(26, 0);
        for (const char & t : tasks) {
            taskFrequency[t - 'A']++;
        }
        priority_queue<int> pq;
        for (const int & f : taskFrequency) {
            if (f > 0) pq.push(f);
        }
        int time = 0;
        queue<pair<int, int>> cooldown; // (frequency, returnTime)
        while (!pq.empty() || !cooldown.empty()) {
            time++;
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                if (freq > 1) cooldown.push({freq - 1, time + n});
            }
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};