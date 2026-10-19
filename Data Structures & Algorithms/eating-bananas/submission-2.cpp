class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minK = INT_MAX;
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            int k = (left + right) / 2;
            long time = 0;

            for (const int & p : piles) {
                time += max(1, (p + k - 1) / k);
            }

            if (time > h) {
                left = k + 1;
                continue;
            }

            minK = min(minK, k);
            right = k - 1;
        }

        return minK;
    }
};
