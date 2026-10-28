class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        perms = []
        visited = set()

        def dfs(i, perm):
            print(perm)
            if i >= len(nums):
                perms.append(perm.copy())
                return
            
            for j in range(len(nums)):
                if j not in visited:
                    visited.add(j)
                    perm.append(nums[j])
                    dfs(i + 1, perm)
                    perm.pop()
                    visited.remove(j)
        
        dfs(0, [])
        return perms