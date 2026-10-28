class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        subsets = set()
        subset = []
        def dfs(i):
            if i >= len(nums):
                subsets.add(tuple(sorted(subset)))
                return
            
            subset.append(nums[i])
            dfs(i + 1)
            subset.pop()
            dfs(i + 1)
        
        dfs(0)
        return [list(sub) for sub in subsets]