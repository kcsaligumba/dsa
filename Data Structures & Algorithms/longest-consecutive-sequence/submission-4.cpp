class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int longest = 0;

        for (const int & n : nums) { // for every number n in nums
            if (!mp[n]) {
                mp[n] = mp[n - 1] + mp[n + 1] + 1;
                mp[n - mp[n - 1]] = mp[n];
                mp[n + mp[n + 1]] = mp[n];
                longest = max(longest, mp[n]);
            }
        }
        return longest;
    }
};
