class MedianFinder {
private: 
    vector<double> nums;
    int medIdx;
    bool odd;
public:
    MedianFinder() {
        medIdx = -1;
        odd = false;
    }
    
    void addNum(int num) {
        nums.push_back(num);
        sort(nums.begin(), nums.end());
        if (!odd) medIdx++;
        odd = !odd;
    }
    
    double findMedian() {
        if (odd) return nums[medIdx];
        return (nums[medIdx] + nums[medIdx + 1]) / 2;
    }
};
