class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        queue = deque([(0, 0)])
        seen = set({0})
        while queue:
            cur, jumps = queue.popleft()
            if cur == n - 1:
                return jumps
            
            for d in range(1, nums[cur] + 1):
                if cur + d >= n or (cur + d) in seen:
                    continue
                queue.append((cur + d, jumps + 1))
                seen.add(cur + d)
        return -1