class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_freq;
        for (int n : nums) {
            num_to_freq[n]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for (const auto& [num, freq] : num_to_freq) {
            maxHeap.push({freq, num});
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};
