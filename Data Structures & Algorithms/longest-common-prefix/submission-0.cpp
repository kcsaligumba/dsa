class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            string curr = strs[i];
            for (int i = 0; i < max(res.length(), curr.length()); i++) {
                if (res[i] != curr[i]) {
                    res = res.substr(0, i);
                    break;
                }
            }
        }

        return res;
    }
};