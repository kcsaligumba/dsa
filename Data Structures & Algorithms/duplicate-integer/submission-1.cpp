class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> numToFreq;
        for (int n : nums) {
            numToFreq[n]++;
            if (numToFreq[n] == 2) {
                return true;
            }
        }
        return false;
    }
};