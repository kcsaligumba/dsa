class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagrams[key].push_back(str);
        }

        vector<vector<string>> res;
        res.reserve(anagrams.size());
        for (const auto& [key, words] : anagrams) {
            res.push_back(move(words));
        }

        return res;
    }
};
