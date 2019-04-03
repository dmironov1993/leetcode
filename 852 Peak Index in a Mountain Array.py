# https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
# First algorithmic solution based on QuickSort algorithm with
# Hoare partition
        arr = A.copy()
        import sys
        sys.setrecursionlimit(15000)

        # Hoare partition
        def Partition(A, p, r):
            x = A[p]
           i = p - 1
           j = r + 1
           while True:
               while True:
                   j = j - 1
                   if A[j] <= x:
                       break
               while True:
                   i = i + 1
                   if A[i] >= x:
                       break
               if i < j:
                   A[i], A[j] = A[j], A[i]
               else:
                   return j
        
       def QuickSort(A,p,r):
           if p < r:
               q = Partition(A,p,r)
               QuickSort(A,p,q)
               QuickSort(A,q+1,r)
        
        # apply sorting
        QuickSort(arr,0,len(arr)-1)
        max_el = arr[-1]
        
        idx = 0
        for i in range(len(arr)):
            if A[i] == max_el:
                idx = i
        return idx

# Second solution (straight forward)  
"""
        k = 0
        for i in range(1,len(A)):
            if A[k] < A[i]:
                k = i
        return k
"""
