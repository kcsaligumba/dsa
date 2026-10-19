class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0
        
        res = 1
        pow = abs(n)
        
        while pow:
            if pow & 1: # odd
                res *= x
            x *= x
            pow >>= 1
        
        return res if n >= 0 else 1 / res