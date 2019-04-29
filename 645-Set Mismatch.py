# https://leetcode.com/problems/guess-number-higher-or-lower/

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        list_ = [x for x in range(1,len(nums)+1)]
        missing = list(set(list_) - set(nums))[0]

        nums = sorted(nums)
        dct = {}
        number = None
        for i in range(len(nums)):
            if nums[i] not in dct.keys():
                dct[nums[i]] = 1
            else:
                dct[nums[i]] += 1
                if dct[nums[i]] == 2:
                    number = nums[i]
                    break
        if missing > number:
            return [number, missing]
        else:
            return [number, missing]
