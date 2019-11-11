//First solution

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        vector<int> res;
        res.reserve(a.size()); // резервируем память
        for (int e : a) {
            if ((e & 1) == 0) {// e % 2 == 0
                res.push_back(e);
            } 
        }
        for (int e: a) {
            if ((e & 1) != 0) {
                res.push_back(e);
            }
        }
        assert(res.size() == a.size());
        return res;
    }
};

//Second solution
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int i = 0;
        int j = (int)a.size() - 1;
        while (true) {
            while (i < j && (a[i] & 1) == 0) {
                i++;
            }
            while (i < j && (a[j] & 1) != 0) {
                j--;
            }
            if (i < j) {
                swap(a[i], a[j]);
                i++;
                j--;
            } else {
                break;
            }
        }
        return move(a);
    }
};
