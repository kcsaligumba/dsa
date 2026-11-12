class Solution:
    def decodeString(self, s: str) -> str:
        output, rep = "", ""
        i = 0
        while i < len(s):
            if 'a' <= s[i] <= 'z':
                output += s[i]
                i += 1
            elif '0' <= s[i] <= '9':
                rep += s[i]
                i += 1
            elif s[i] == '[':
                j = i + 1
                skip = 0
                while j < len(s):
                    if s[j] == ']':
                        if skip == 0:
                            break
                        skip -= 1
                    elif s[j] == '[':
                        skip += 1
                    j += 1
                output += self.decodeString(s[i + 1:j]) * int(rep)
                rep = ""
                i = j + 1
        
        return output