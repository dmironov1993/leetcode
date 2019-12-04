//https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& a) {
        int n = (int)a.size();
        vector<int> L(n);
        L[0] = 1;
        L[1] = a[0];
        for (int i = 2; i < n; i++) {
                L[i] = a[i-1]*L[i-1];
        }
        vector<int> R(n);
        R[n-1] = 1;
        R[n-2] = a[n-1];
        for (int i = n-3; i >= 0; i--) {
                R[i] = a[i+1]*R[i+1];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(L[i]*R[i]);
        }
        return ans;
    }
};
