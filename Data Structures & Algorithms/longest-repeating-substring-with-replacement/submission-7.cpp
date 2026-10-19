class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int mostFreq = 0;
        int maxLength = 0;
        int left = 0;
        int right = 0;

        while (right < s.length()) {
            count[s[right]]++;
            mostFreq = max(mostFreq, count[s[right]]);
            right++;

            if ((right - left) - mostFreq <= k) {
                maxLength = max(maxLength, right - left);
            }
            else {
                count[s[left]]--;
                left++;
            }
        }

        return maxLength;
    }
};
