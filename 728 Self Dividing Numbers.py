class Solution:
    def selfDividingNumbers(self, left: 'int', right: 'int') -> 'List[int]':
        ans = []
        for number in range(left, right + 1):
            all_divisors = list(map(int, list(str(number))))
            loc_result = []
            for element in all_divisors:
                if element != 0 and number%element == 0:
                    loc_result.append(0)
                elif element == 0:
                    loc_result.append(1)
                else:
                    loc_result.append(1)
            if sum(loc_result) == 0:
                ans.append(number)
        return ans
