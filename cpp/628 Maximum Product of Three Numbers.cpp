//Solution with priority_queue
class Solution {
public:
    int maximumProduct(vector<int>& a) {
        priority_queue<int, vector<int>, greater<int>> maxim;
        priority_queue<int> minim;
        for (int v: a) {
            maxim.push(v);
            if (maxim.size() > 3) {
                maxim.pop();
            }
            minim.push(v);
            if (minim.size() > 2) {
                minim.pop();
            }
        }
        //max1 >= max2 >= max3
        int max3 = maxim.top();
        maxim.pop();
        int max2 = maxim.top();
        maxim.pop();
        int max1 = maxim.top();

        //min2 >= min1
        int min2 = minim.top();
        minim.pop();
        int min1 = minim.top();
            
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};




//Solution with the use of nth_element
class Solution {
public:
    int maximumProduct(vector<int>& a) {
        nth_element(a.begin(), a.begin() + 1, a.end());
        int a0 = a[0];
        int a1 = a[1];
        nth_element(a.begin(), a.end()-3, a.end());
        sort(a.end() - 3, a.end());
        int sz = (int)a.size();
        return max(a0*a1*a[sz-1], a[sz-3]*a[sz-2]*a[sz-1]);
    }
};




//O(nlog(n))
//Runtime: 68 ms and Memory Usage: 11 MB
//Passes all LeetCode tests
class Solution {
public:
    int maximumProduct(vector<int>& a) {
        sort(a.begin(), a.end());
        int sz = (int)a.size();
        return max(a[0]*a[1]*a[sz-1], a[sz-3]*a[sz-2]*a[sz-1]);
    }
};




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

