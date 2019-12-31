//My own solution (not perfect)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        vector<int> num;
        while (x != 0) {
            num.push_back(x%10);
            x /= 10;
        }
        vector<int> rev;
        rev = num;
        reverse(rev.begin(), rev.end());
        if (rev == num) {
            return true;
        }
        return false;
    }
};

//Solution taken from here: 
//https://www.youtube.com/watch?v=CumLEmaPero&list=PLES6U-jjEXscLKgGQkLglfLn7myfyGtjj&index=11
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int rev = 0;
        int cur = x;
        while (cur > 0) {
            int d = cur % 10;
            cur /= 10;
            if (rev < INT_MAX / 10 || (rev == INT_MAX / 10 && d <= INT_MAX % 10)) {
                rev = rev * 10 + d;
            } else {
                return false;
            }            
        }
        return rev == x;
    }
};
