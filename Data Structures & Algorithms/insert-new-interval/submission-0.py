class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        newStart, newEnd = newInterval
        result = []

        for i in range(len(intervals)):
            if newEnd < intervals[i][0]:
                result.append(newInterval)
                result.extend(intervals[i:])
                return result
            elif newStart > intervals[i][1]:
                result.append(intervals[i])
            else:
                newStart = min(newStart, intervals[i][0])
                newEnd = max(newEnd, intervals[i][1])
                newInterval = [newStart, newEnd]
        
        result.append(newInterval)
        return result