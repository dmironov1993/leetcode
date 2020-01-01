//My solution which was created really fast
//Probably it is not effective much in terms of number of operations

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int stopf = 0;
        for (int i = 0; i < (int)S.size(); i++) {
            if (S[i] == C) {
                stopf = i;
                break;
            }
        }
        int stopb = 0;
        for (int i = (int)S.size() - 1; i >= 0; i--) {
            if (S[i] == C) {
                stopb = i;
                break;
            }
        }
        
        vector<int> forward;
        int cntf = 1;
        for (int i = 0; i < (int)S.size(); i++) {
            if (i < stopf) {
                forward.push_back(INT_MAX);
            } else {
                if (S[i] == C) {
                    forward.push_back(0);
                    cntf = 1;
                } else {
                    forward.push_back(cntf);
                    cntf++;
                }
            }
        }
        
        vector<int> backward;
        int cnfb = 1;
        for (int i = (int)S.size() - 1; i >= 0; i--) {
            if (i > stopb) {
                backward.push_back(INT_MAX);
            } else {
                if (S[i] == C) {
                    backward.push_back(0);
                    cnfb = 1;
                } else {
                    backward.push_back(cnfb);
                    cnfb++;
                }
            }
        }
        
        reverse(backward.begin(), backward.end());
        vector<int> f;
        for (int i = 0; i < (int)S.size(); i++) {
            if (forward[i] < backward[i]) {
                f.push_back(forward[i]);
            } else {
                f.push_back(backward[i]);
            }
        }
        return f;
    }
};
