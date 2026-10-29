class TrieNode:

    def __init__(self):
        self.children = {}
        self.isWord = False

    def insert(self, word: str) -> None:
        cur = self
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.isWord = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        n, m = len(board), len(board[0])
        neighbors = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        root = TrieNode()
        for word in words:
            root.insert(word)
        
        res, visited = set(), set()
        def dfs(r, c, node, word):
            if (r not in range(n) or 
                c not in range(m) or
                (r, c) in visited or
                board[r][c] not in node.children):
                return
            
            visited.add((r, c))
            node = node.children[board[r][c]]
            word += board[r][c]

            if node.isWord:
                res.add(word)

            for dr, dc in neighbors:
                nr, nc = r + dr, c + dc
                dfs(nr, nc, node, word)
            
            visited.remove((r, c))

        for r in range(n):
            for c in range(m):
                dfs(r, c, root, "")
        
        return list(res)
        