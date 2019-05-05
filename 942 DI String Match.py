class Solution:
    def diStringMatch(self, S: 'str') -> 'List[int]':
        sm, la = 0, len(S)
        ans = []
        for i in range(len(S)):
            if S[i] == 'I':
                ans.append(sm)
                sm = sm + 1
            else:
                ans.append(la)
                la = la - 1
        ans.append(la)
        return ans
