class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        queue = deque([i for i in range(n) if dominoes[i] != '.'])
        dominoes = list(dominoes)
        while queue:
            size = len(queue)
            for _ in range(size):
                i = queue.popleft()
                d = dominoes[i]
                if d == '.':
                    continue
                if d == 'L' and i > 0:
                    if dominoes[i - 1] == '.':
                        queue.append(i - 1)
                        dominoes[i - 1] = 'l'
                    elif dominoes[i - 1] == 'r':
                        dominoes[i - 1] = '.'
                elif d == 'R' and i < n - 1:
                    if dominoes[i + 1] == '.':
                        dominoes[i + 1] = 'r'
                        queue.append(i + 1)
                    elif dominoes[i + 1] == 'l':
                        dominoes[i + 1] = '.'
            for i in queue:
                if dominoes[i] == 'l':
                    dominoes[i] = 'L'
                elif dominoes[i] == 'r':
                    dominoes[i] = 'R'
        return "".join(dominoes)
