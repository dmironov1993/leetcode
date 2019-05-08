# https://leetcode.com/problems/valid-anagram/submissions/

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        """ # very slow but straightforward solution
        if len(s) == len(t):
            s, t = list(s), list(t)
            count = 0
            for i in range(len(s)):
                if s[i] in t:
                    count += 1
                    idx = t.index(s[i])
                    t.pop(idx)
            if count == len(s):
                return True
            else:
                return False
        else:
            return False
        """
        
        return sorted(s) == sorted(t)
