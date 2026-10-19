class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), 
            [](const auto & c1, auto & c2) { return c1.first > c2.first; });
        
        int res = 1;
        double catchUpTo = (double) (target - cars[0].first) / cars[0].second;
        for (int i = 1; i < cars.size(); i++) {
            pair<int, int> c = cars[i];
            double hours = (double) (target - c.first) / c.second;
            if (hours > catchUpTo) {
                res++;
                catchUpTo = hours;
            }
        }

        return res;
    }
};
