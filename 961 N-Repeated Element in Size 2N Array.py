# https://leetcode.com/problems/n-repeated-element-in-size-2n-array/ 

class Solution:
    def repeatedNTimes(self, A: 'List[int]') -> 'int':
        return int((sum(A) - sum(set(A))) / (len(A)/ 2 -1))
