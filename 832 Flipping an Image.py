class Solution:
    def flipAndInvertImage(self, A: 'List[List[int]]') -> 'List[List[int]]':
        B = A
        N = len(B)
        dct = {0:1, 1:0}
        row = []
        for i in range(N):
            B[i].reverse()
        for j in B:
            element = list(map(dct.get, j))
            row.append(element)
        return row
