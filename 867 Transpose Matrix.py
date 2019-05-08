# https://leetcode.com/problems/transpose-matrix/

class Solution:
    def transpose(self, A: 'List[List[int]]') -> 'List[List[int]]':
        return list(map(list, zip(*A)))
