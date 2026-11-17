class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2, = nums2, nums1
        m, n = len(nums1), len(nums2)
        total = m + n
        half = total // 2
        
        left, right = 0, len(nums1) - 1
        while True:
            mid1 = (right + left) // 2
            mid2 = half - mid1 - 2

            lp1 = nums1[mid1] if mid1 >= 0 else float('-inf')
            rp1 = nums1[mid1 + 1] if mid1 + 1 < m else float('inf')
            lp2 = nums2[mid2] if mid2 >= 0 else float('-inf')
            rp2 = nums2[mid2 + 1] if mid2 + 1 < n else float('inf')

            if lp1 <= rp2 and lp2 <= rp1:
                if total % 2:
                    return min(rp1, rp2)
                return (max(lp1, lp2) + min(rp1, rp2)) / 2
            elif lp1 > rp2:
                right = mid1 - 1
            else:
                left = mid1 + 1