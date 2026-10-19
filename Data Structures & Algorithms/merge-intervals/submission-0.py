class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        start = []
        end = []
        n = -1

        for i in range(len(intervals)):
            s = intervals[i][0]
            e = intervals[i][1]
            
            if n == -1:
                start.append(s)
                end.append(e)
                n += 1
                continue
            
            if s > end[n]:
                start.append(s)
                end.append(e)
                n += 1
            elif e > end[n]:
                end[n] = e
        
        return [[a, b] for a, b in zip(start, end)]