//First solution
class Solution {
public:
    
    bool isLetter(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }
    
    string reverseOnlyLetters(const string &s) {
        string res = s;
        int dst = (int)res.size() - 1;
        for (int src = 0; src < (int)s.size(); src++) {
            if (isLetter(s[src])) {
                while (!isLetter(res[dst])) {
                    dst--;
                    assert(dst >= 0);
                }
                res[dst] = s[src];
                dst--;
            }
        }
        return res;
    } 
};



//Second solution
class Solution {
public:
    
    bool isLetter(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }
    
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = (int)s.size() - 1;
        while (true) {
            while (i < j and not (isLetter(s[i]))) {
                i++;
            }
            while (i < j and not (isLetter(s[j]))) {
                j--;
            }
            if (i < j) {
                swap(s[i],s[j]);
                i++;
                j--;
            } else {
                break;
            }
        }
        return move(s);
    }
};



//My solution
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
