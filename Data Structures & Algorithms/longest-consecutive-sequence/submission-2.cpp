class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int count = 1;
        int largest = 1;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            
            if (nums[i] == nums[i - 1] + 1) {
                count++;
            }
            else {
                if (count > largest) {
                    largest = count;
                }
                count = 1;
            }
        }

        if (count > largest) {
            return count;
        }

        return largest;
    }
};
