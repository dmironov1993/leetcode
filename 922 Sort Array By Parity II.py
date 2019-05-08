class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        for i in range(len(A)):
            if (A[i]%2==0 and i%2==0) or (A[i]%2!=0 and i%2!=0):
                continue
            else:
                for j in range(i,len(A)):
                    if A[i]%2==0 and i%2!=0 and A[j]%2!=0 and j%2==0:
                        tmp = A[j]
                        A[j] = A[i]
                        A[i] = tmp
                        break
                    elif A[i]%2!=0 and i%2==0 and A[j]%2==0 and j%2!=0:
                        tmp = A[j]
                        A[j] = A[i]
                        A[i] = tmp
                        break
        return A
