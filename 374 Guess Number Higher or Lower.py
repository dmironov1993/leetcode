# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

# https://leetcode.com/problems/guess-number-higher-or-lower/

import math
class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low = 1
        high = n
        while low <= high:
            mid = math.floor((low+high)/2)
            if guess(mid) == 0:
                return int(mid)
            elif guess(mid) == 1:
                low = mid + 1
            else:
                high = mid - 1