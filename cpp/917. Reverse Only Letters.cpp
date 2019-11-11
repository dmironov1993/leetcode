class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = (int)s.size() - 1;
        while (true) {
            while (i < j and not (isalpha(s[i]))) {
                i += 1;
            }
            while (i < j and not (isalpha(s[j]))) {
                j -= 1;
            }
            if (i < j) {
                swap(s[i],s[j]);
                i += 1;
                j -= 1;
            } else {
                break;
            }
        }
        return s;
    }
};
