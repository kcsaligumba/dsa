class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }

        int maxLength = 1;
        int left = 0;
        int right = 1;
        unordered_set<char> substr = {s[0]};
        
        while (right < s.length()) {
            while(substr.count(s[right])) {
                substr.erase(s[left]);
                left++;
            }
            substr.insert(s[right]);
            right++;
            
            maxLength = max(maxLength, (int) substr.size());
        }

        return maxLength;
    }
};
