class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        val_to_idx = {}

        for i, n in enumerate(nums):
            if n in val_to_idx and abs(i - val_to_idx[n]) <= k:
                return True
            val_to_idx[n] = i
        
        return False