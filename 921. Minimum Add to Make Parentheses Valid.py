# https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        def doors(S):
            required_open = 0
            required_close = 0
            count_open = 0
            for el in S:
                if el == ')' and count_open == 0:
                    required_open += 1
                elif el == ')' and count_open > 0:
                    count_open -= 1
                    required_close -= 1
                elif el == '(':
                    count_open += 1
                    required_close += 1
            return required_open + required_close
        
        ans = doors(S)
        return ans
