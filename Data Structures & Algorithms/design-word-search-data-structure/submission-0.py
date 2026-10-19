class Node:

    def __init__(self):
        self.children = {} # letter -> Node
        self.end = False

class WordDictionary:

    def __init__(self):
        self.tree = Node()

    def addWord(self, word: str) -> None:
        cur = self.tree
        for c in word:
            if c not in cur.children:
                cur.children[c] = Node()
                cur = cur.children[c]
            else:
                cur = cur.children[c]
        if cur != self.tree:
            cur.end = True            

    def search(self, word: str) -> bool:
        def helper(node, index):
            cur = node
            
            for i in range(index, len(word)):
                c = word[i]

                if c == '.':
                    for l in cur.children.values():
                        if helper(l, i + 1):
                            return True
                    return False
                
                if c not in cur.children:
                    return False
                
                cur = cur.children[c]
            
            return cur.end
        
        return helper(self.tree, 0)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)