from random import randrange

class Solution:

    def __init__(self, w: List[int]):
        self.ranges = [(0, w[0])]
        self.max = w[0]
        for i in range(1, len(w)):
            start = self.ranges[i - 1][1]
            end = start + w[i]
            self.ranges.append((start, end))
            self.max = end

    def pickIndex(self) -> int:
        random = randrange(self.max)
        left, right = 0, len(self.ranges) - 1
        while left <= right:
            mid = (right + left) // 2
            low, high = self.ranges[mid]
            if low <= random < high:
                return mid
            if random < low:
                right = mid - 1
            elif random >= high:
                left = mid + 1


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()