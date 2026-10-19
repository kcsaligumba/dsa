class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> data; 

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (data.count(key)) {
            data[key].push_back({timestamp, value});
        } else data[key] = {{timestamp, value}};
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> k = data[key];
        if (k.empty()) return "";
        int left = 0;
        int right = k.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (timestamp == k[mid].first) return k[mid].second;
            if (timestamp > k[mid].first) left = mid + 1;
            else right = mid - 1;
        }
        if (timestamp > k[mid].first) return k[mid].second;
        return (mid - 1 >= 0) ? k[mid - 1].second : "";
    }
};
