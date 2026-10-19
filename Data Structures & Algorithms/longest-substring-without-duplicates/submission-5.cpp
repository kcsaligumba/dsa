class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        unordered_set<char> substr;
        
        for (int right = 0; right < s.length(); right++) {
            while(substr.count(s[right])) {
                substr.erase(s[left]);
                left++;
            }
            substr.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
