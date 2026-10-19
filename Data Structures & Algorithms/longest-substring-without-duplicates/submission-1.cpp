class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        
        int maxLength = 1;
        int left = 0;
        int right = 1;
        int length = 1;
        unordered_set<char> substr = {s[0]};
        
        while (right < s.length()) {
            if (!substr.count(s[right])) {
                length++;
            }
            else {
                maxLength = max(maxLength, length);
                length++;
                while (substr.count(s[right])) {
                    substr.erase(s[left]);
                    left++;
                    length--;
                }
                
            }
            substr.insert(s[right]);
            right++;
        }

        maxLength = max(maxLength, length);
        return maxLength;
    }
};
