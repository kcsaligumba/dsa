class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int left = 0;
        int right = 0;
        deque<int> q;

        while (right < nums.size()) {
            while (!q.empty() && nums[q.back()] < nums[right]) {
                q.pop_back();
            }

            q.push_back(right);

            if (left > q.front()) {
                q.pop_front();
            }

            if (right - left + 1 >= k) {
                res.push_back(nums[q.front()]);
                left++;
            }

            right++;
        }

        return res;
    }
};
