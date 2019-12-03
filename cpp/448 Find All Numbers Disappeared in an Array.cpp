//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
//https://www.youtube.com/watch?v=x6X_v_LJ-VU

//First solution
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        for (int x : a) {
            int i = abs(x) - 1;
            if (a[i] > 0) {
                a[i] = -a[i];
            }
        }
        vector<int> ans;
        for (int v = 1; v <= (int)a.size(); v++) {
            int i = v - 1;
            if (a[i] > 0) {
                ans.push_back(v);
            }
        }
        return ans;
    }
};

//Second solution
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        for (int i = 0; i < (int)a.size(); i++) {
            while (true) {
                int j = a[i] - 1;
                if (a[j] == a[i]) {
                    break;
                }
                swap(a[i], a[j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] != i + 1) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
