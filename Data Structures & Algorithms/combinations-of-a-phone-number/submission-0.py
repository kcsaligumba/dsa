class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        
        res = []
        toLetter = {
            '2' : "abc",
            '3' : "def",
            '4' : "ghi",
            '5' : "jkl",
            '6' : "mno",
            '7' : "pqrs",
            '8' : "tuv",
            '9' : "wxyz"
        }

        def findCombos(i, curStr):
            if i >= len(digits):
                res.append(curStr)
                return 
            
            for l in toLetter[digits[i]]:
                findCombos(i + 1, curStr + l)
        
        findCombos(0, "")
        return res