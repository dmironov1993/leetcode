# https://leetcode.com/problems/fibonacci-number/

class Solution:
    def fib(self, N: 'int') -> 'int':
        first = 0
        second = 1
        if N == 0:
            return first
        elif N == 1:
            return second
        if N >=2:
            new = 0
            for i in range(2,N+1):
                new = first + second
                first = second
                second = new
            return new
