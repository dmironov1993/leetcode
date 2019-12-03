//https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pos1=0, pos2=1;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (nums[pos1] == nums[pos2]) {
                return true;
            }
            ++pos1;
            ++pos2;
        }
        return false;
    }
};
