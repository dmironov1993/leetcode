//Hybrid of Bubble sort
//Runtime: 1588 ms and Memory Usage: 10.9 MB
//Passes all LeetCode tests
class Solution {
public:
    int maximumProduct(vector<int>& a) {
        for (int i = 0; i < (int)a.size(); i++) {
            int min = a[i];
            int minI = i;
            for (int j = i+1; j < (int)a.size(); j++) {
                if (a[j] < min) {
                    min = a[j];
                    minI = j;
                }
            }
            swap(a[i],a[minI]);
        }
        int sz = (int)a.size();
        return max(a[0]*a[1]*a[sz-1], a[sz-3]*a[sz-2]*a[sz-1]);
    }
};

//Bubble sort
//It's correct but does not pass time-limit constraints
class Solution {
public:
    int maximumProduct(vector<int>& a) {
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = (int)a.size() - 2; j >= i; j--) {
                if (a[j+1] < a[j]) {
                    swap(a[j], a[j+1]);
                }
            }
        }
        int sz = (int)a.size();
        return max(a[0]*a[1]*a[sz-1], a[sz-3]*a[sz-2]*a[sz-1]);
    }
};


//Naive solutions O(n^3)
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

