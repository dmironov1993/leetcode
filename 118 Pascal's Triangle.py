class Solution:
    def generate(self, numRows: 'int') -> 'List[List[int]]':
        
        def factorial(p):
            if p == 0:
                return 1
            if p == 1:
                return 1
            if p > 1:
                return p*factorial(p-1)
    
        N = numRows
        ans = []
        for n in range(0,N):
            sublist = []
            for k in range(n+1):
                binom = int(factorial(n)/(factorial(k)*factorial(n-k)))
                sublist.append(binom)
            ans.append(sublist)
            
        return ans
