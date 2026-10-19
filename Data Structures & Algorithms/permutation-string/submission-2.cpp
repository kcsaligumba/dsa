class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) {
            return false;
        }

        vector<int> freq1(26);
        vector<int> freq2(26);
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int left = 0;
        for (int right = s1.length(); right < s2.length(); right++) {
            if (freq2 == freq1) {
                return true;
            }

            freq2[s2[left] - 'a']--;
            freq2[s2[right] - 'a']++;

            left++;
        }

        return freq2 == freq1;
    }
};
