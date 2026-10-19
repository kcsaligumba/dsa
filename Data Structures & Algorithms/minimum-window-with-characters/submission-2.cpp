class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") {
            return "";
        }

        unordered_map<char, int> countT;
        unordered_map<char, int> countS;

        for (const char & c : t) {
            countT[c]++;
        }

        int have = 0;
        int need = countT.size();
        int left = 0;
        pair<int, int> res(-1, -1);
        int resLen = INT_MAX;

        for (int right = 0; right < s.length(); right++) {
            countS[s[right]]++;

            if (countT.count(s[right]) && countS[s[right]] == countT[s[right]]) {
                have++;
            }

            while (have == need) {
                if (right - left + 1 < resLen) {
                    res = {left, right};
                    resLen = right - left + 1;
                }

                countS[s[left]]--;
                if (countT.count(s[left]) && countS[s[left]] < countT[s[left]]) {
                    have--;
                }

                left++;
            }
        }
        
        if (resLen != INT_MAX) { 
            return s.substr(res.first, resLen);
        }
        return "";
    }
};
