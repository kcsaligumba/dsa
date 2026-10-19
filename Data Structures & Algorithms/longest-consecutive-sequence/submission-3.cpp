class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set set(nums.begin(), nums.end());
        int longest = 0;
        int length;
        for (const int & n : nums) { // for every number n in nums
            if (!set.count(n - 1)) { // if n is the start of a sequence(has no left neighbor)
                length = 0;
                while (set.count(n + length)) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
