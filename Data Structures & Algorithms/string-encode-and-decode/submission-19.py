class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return "None"
        encoded_string = "/".join(strs)
        return encoded_string
    def decode(self, s: str) -> List[str]:
        if s == "None":
            decoded_string = "".split()
        else:
            decoded_string = s.split("/")
        return decoded_string