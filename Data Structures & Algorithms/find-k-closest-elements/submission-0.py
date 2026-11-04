class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        cur_dist = sum(abs(n - x) for n in arr[:k])
        best_start = 0
        best_dist = cur_dist
        for i in range(k, len(arr)):
            cur_dist -= abs(arr[i - k] - x)
            cur_dist += abs(arr[i] - x)
            if cur_dist < best_dist:
                best_dist = cur_dist
                best_start = i - k + 1
        return arr[best_start : best_start + k]