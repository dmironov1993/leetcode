class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        vector<int> res(a.size());
        int even = 0;
        int odd = 1;
        for (int e : a) {
            if ((e & 1) == 0) {
                res[even] = e;
                even += 2;
            } else {
                res[odd] = e;
                odd += 2;
            }
        }
        return res;
    }
};
