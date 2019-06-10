# https://leetcode.com/problems/valid-perfect-square/

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if int(num**(1/2))**2 == num:
            return True
        else:
            return False
