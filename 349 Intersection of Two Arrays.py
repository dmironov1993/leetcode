# https://leetcode.com/problems/intersection-of-two-arrays/

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:

        """
        n1, n2 = len(nums1), len(nums2)
        n, list_, small = 0, None, None
        if n1 > n2:
            n, large, small = n2, nums1, nums2
        else:
            n, large, small = n1, nums2, nums1
        a = []
        for i in range(n):
            if small[i] in large:
                a.append(small[i])
        return list(a)
    """
        return list(set(nums2)-(set(nums2) - set(nums1)))
