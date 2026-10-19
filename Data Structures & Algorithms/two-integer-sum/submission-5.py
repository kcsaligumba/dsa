class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        penis = {}
        for i, val in enumerate(nums):
            diff = target - val
            if diff in penis:
                return [penis[diff] , i]

            else: 
                penis.update({val : i})
        
        
        #for i, n in enumerate(nums):
           # diff = target - n
            #if (diff in nums):
               # return [i, nums.index(diff)]
