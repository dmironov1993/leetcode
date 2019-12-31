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
