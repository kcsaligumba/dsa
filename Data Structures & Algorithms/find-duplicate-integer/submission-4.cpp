class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) break;
        }
        int res = 0;
        while (true) {
            res = nums[res];
            slow = nums[slow];
            if (res == slow) return res;
        }
    }
};
