class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSum = {
            0: 1
        }
        curSum, count = 0, 0

        for n in nums:
            curSum += n
            diff = curSum - k
            if diff in prefixSum:
                count += prefixSum[diff]
            prefixSum[curSum] = prefixSum.get(curSum, 0) + 1
        
        return count
        