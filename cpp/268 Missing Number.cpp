//https://leetcode.com/problems/missing-number/

//First solution when sum can be represented as int type
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


//Second solution which is very similar to the first one but sum is represented as long long type this time
class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        long long s = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            s += nums[i];
        }
        long long n = (int)nums.size();
        long long res = n*(n+1) / 2 - s;
        if (res == 0) {
            return 0;
        } else {
            return res;
        }
    }
};


//Third solution (similar to those above but more elegant)
//Taken from https://www.youtube.com/watch?v=yVkWvWpHXhc
class Solution {
public:
    int missingNumber(const vector<int>& a) {
        int n = (int)a.size(); //max 3 037 000 499
        long long sum = n* (n + 1LL) / 2;
        for (int v: a) {
            sum -= v;
        }
        return (int)sum;
    }
};
