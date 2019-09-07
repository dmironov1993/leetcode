// https://leetcode.com/problems/maximum-subarray/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0], sum = nums[0];
        for (int k = 1; k < nums.size(); k++) {
            sum = max(nums[k], sum+nums[k]);
            best = max(sum, best);
        }
        return best;
    }
};
