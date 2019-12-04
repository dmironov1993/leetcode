// Naive solutions O(n^3)
//It's correct but does not pass time-limit constraints
class Solution {
public:
    int maximumProduct(vector<int>& a) {
        int ans = INT_MIN;
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = i+1; j < (int)a.size(); j++) {
                for (int k = j+1; k < (int)a.size(); k++) {
                    ans = max(ans, a[i]*a[j]*a[k]);
                }
            }
        }
        return ans;
    }
};

