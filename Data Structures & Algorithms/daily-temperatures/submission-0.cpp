class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for (int i = 0; i < temperatures.size(); i++) {
            int size = res.size();
            for (int j = i + 1; j < temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    res.push_back(j - i);
                    break;
                }
            }
            if (res.size() == size) res.push_back(0);
        }
        return res;
    }
};
