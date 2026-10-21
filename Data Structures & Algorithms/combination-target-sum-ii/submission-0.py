class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        stack = [(-1, 0, [])] # last used index, running sum, path
        while stack:
            idx, total, path = stack.pop()
            if total == target:
                result.append(path)
                continue
            for j in range(idx + 1, len(candidates)):
                if j > idx + 1 and candidates[j] == candidates[j - 1]:
                    continue  # same value already tried at this level
                if total + candidates[j] > target:
                    break  # sorted, so everything after is too big too
                stack.append((j, total + candidates[j], path + [candidates[j]]))
        return result