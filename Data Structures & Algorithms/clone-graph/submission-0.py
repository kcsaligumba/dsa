"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        
        old_to_new = {}
        old_to_new[node] = Node(node.val)
        stack = [node]
        visited = set()

        while stack:
            old = stack.pop()
            new = old_to_new[old]

            if old.val in visited:
                continue
            visited.add(old.val)

            for nei in old.neighbors:
                if nei not in old_to_new:
                    new_nei = Node(nei.val)
                    old_to_new[nei] = new_nei
                else:
                    new_nei = old_to_new[nei]
                new.neighbors.append(new_nei)
                stack.append(nei)
        
        return old_to_new[node]


