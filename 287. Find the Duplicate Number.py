# https://leetcode.com/problems/find-the-duplicate-number/


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        arr = sorted(nums)
        n = len(arr)
        for i in range(n-1):
            if arr[i] == arr[i+1]:
                return arr[i]
