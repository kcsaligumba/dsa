class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        nodes = []
        dashes, i = 0, 0
        while i < len(traversal):
            if traversal[i] == '-':
                dashes += 1
                i += 1
            else:
                j = i
                while j < len(traversal) and traversal[j] != '-':
                    j += 1
                nodes.append('-' * dashes + traversal[i:j])
                dashes = 0
                i = j
        
        n = 0
        def build(depth: int):
            nonlocal n

            if n >= len(nodes):
                return None
            
            if nodes[n].count('-') == depth:
                node = TreeNode(int(nodes[n].strip('-')))
                n += 1
                node.left = build(depth + 1)
                node.right = build(depth + 1)
                return node
            
            return None
        
        return build(0)
