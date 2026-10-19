class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        toReturn = [] 
        prefix = 1
        suffix = 1
        product = 1 

        for i in range(len(nums)):
            for j in range(i):
                prefix *= nums[j]
        
            for k in range(len(nums) - 1, i, -1):
                suffix *= nums[k]
    
            toReturn.append(prefix * suffix)
            prefix = 1
            suffix = 1

        return toReturn