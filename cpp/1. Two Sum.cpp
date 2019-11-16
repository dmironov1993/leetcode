//Second solution
class Solution {
    
    bool canSubtract(int a, int b) {
        return (b >= 0 && a >= INT_MIN + b) || (b < 0 && a - b <= INT_MAX + b);
    }
    
public:
    vector<int> twoSum(const vector<int>& a, int target) {
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < (int)a.size(); i++) {
            if (canSubtract(target, a[i])) {
                auto it = valueToIndex.find(target-a[i]);
                if (it != valueToIndex.end()) {
                    return {it->second, i};
                }
            }
            valueToIndex[a[i]] = i;
        }
        throw invalid_argument("sum not found");
    }
};

//First solution
class Solution {
public:
    vector<int> twoSum(const vector<int>& a, int target) {
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < (int)a.size(); i++) {
            auto it = valueToIndex.find(target-a[i]);
            if (it != valueToIndex.end()) {
                return {it->second, i};
            }
            valueToIndex[a[i]] = i;
        }
        throw invalid_argument("sum not found");
    }
};
