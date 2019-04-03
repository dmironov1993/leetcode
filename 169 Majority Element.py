#https://leetcode.com/problems/majority-element/

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
# Boyer–Moore string-search algorithm
        count = 0
        for i in range(len(nums)):
            if count == 0:
                maj_el = nums[i]
                count = 1
            elif maj_el == nums[i]:
                count += 1
            else:
                count -=1
        return maj_el

