class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        
        m = len(beginWord)
        patterns = defaultdict(list)
        for word in wordList:
            for i in range(m):
                p = word[:i] + "*" + word[i + 1:]
                patterns[p].append(word)
        
        dist = {}
        visited = set()
        q = deque()
        dist[beginWord] = 1
        visited.add(beginWord)
        q.append(beginWord)

        while q:
            word = q.popleft()
            for i in range(m):
                p = word[:i] + "*" + word[i + 1:]
                nbrs = patterns[p]
                for n in nbrs:
                    if n not in visited:
                        dist[n] = dist[word] + 1
                        visited.add(n)
                        q.append(n)
                    if n == endWord:
                        return dist[n]
        
        return 0