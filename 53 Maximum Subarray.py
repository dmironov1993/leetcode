import math

class Solution:
    def maxSubArray(self, nums: 'List[int]') -> 'int':
        
        def Find_Max_Crossing_Subarray(nums, low, mid, high):
            left_sum = -math.inf
            summa = 0
            for i in range(mid, low-1, -1):
                summa += nums[i]
                if summa > left_sum:
                    left_sum = summa
                    max_left = i
            right_sum = -math.inf
            summa = 0
            for j in range(mid+1, high+1):
                summa += nums[j]
                if summa > right_sum:
                    right_sum = summa
                    max_right = j
            return (max_left, max_right, left_sum + right_sum)
        
        def Find_Maximum_Subarray(nums, low, high):
            if high == low:
                return (low, high, nums[low])
            else:
                mid = math.floor((low + high)/2)
                (left_low, left_high, left_sum) = Find_Maximum_Subarray(nums, low, mid)
                (right_low, right_high, right_sum) = Find_Maximum_Subarray(nums, mid+1, high)
                (cross_low, cross_high, cross_sum) = Find_Max_Crossing_Subarray(nums, low, mid, high)
                if left_sum >= right_sum and left_sum >= cross_sum:
                    return (left_low, left_high, left_sum)
                elif right_sum >= left_sum and right_sum >= cross_sum:
                    return (right_low, right_high, right_sum)
                else:
                    return (cross_low, cross_high, cross_sum)
                
                
        low = 0
        high = len(nums)-1
        mid = math.floor((low+high)/2)

        ans = Find_Maximum_Subarray(nums, low, high)[-1]
        return ans
