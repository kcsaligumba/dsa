class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()

        cur = []
        def dfs(i, sum):
            if sum == target:
                res.append(cur.copy())
                return

            for j in range(i, len(nums)):
                if sum + nums[j] > target:
                    return
                
                # include
                cur.append(nums[j])
                dfs(j, sum + nums[j])
                cur.pop()
            
        dfs(0, 0)
        return res