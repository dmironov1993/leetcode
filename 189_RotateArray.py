#https://leetcode.com/problems/rotate-array/

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        first_part = nums[-k:]
        second_part = nums[:-k]
        f = len(first_part)
        s = len(second_part)
        i = 0
        for j in range(f):
            nums[i] = first_part[j]
            i += 1
        for j in range(s):
            nums[i] = second_part[j]
            i += 1
