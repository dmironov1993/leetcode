class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
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
                idx = large.index(small[i])
                large.pop(idx)
        return list(a)
