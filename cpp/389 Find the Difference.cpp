//My solution
//We use XOR operation

class Solution {
public:
    char findTheDifference(string s, string t) {
        string c = s + t;
        char ans = '\0';
        for (int i = 0; i < (int)c.size(); i++) {
            ans ^= c[i];
        }
        return ans;
    }
};
