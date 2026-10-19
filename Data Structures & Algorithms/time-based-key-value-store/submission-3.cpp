class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> data; 

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> & k = data[key];
        string res = "";
        int left = 0;
        int right = k.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (timestamp >= k[mid].first) {
                res = k[mid].second;
                left = mid + 1;
            } else right = mid - 1;
        }
        return res;
    }
};
