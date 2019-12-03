//https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            s += nums[i];
        }
        int n = (int)nums.size();
        int res = n*(n+1) / 2 - s;
        if (res == 0) {
            return 0;
        } else {
            return res;
        }
    }
};
