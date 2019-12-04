//The task - https://leetcode.com/problems/maximum-product-of-three-numbers/
//Solution: https://www.youtube.com/watch?v=psLyGsina4Y

//Straightforward solution 1
class Solution {
public:
    int maximumProduct(vector<int>& a) {
        int n = (int)a.size();
        swap(a[n-1], *max_element(a.begin(), a.end()));
        swap(a[n-2], *max_element(a.begin(), a.end() - 1));
        swap(a[n-3], *max_element(a.begin(), a.end() - 2));
        swap(a[0], *min_element(a.begin(), a.end()));
        swap(a[1], *min_element(a.begin()+1, a.end()));
        return max(a[0] * a[1] * a[n-1], a[n-3] * a[n-2] * a[n-1]);
    }
};




//Straightforward solution 2
class Solution {
public:
    int maximumProduct(const vector<int>& a) {
        int max1 = INT_MIN; //the largest
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX; //the smallest
        int min2 = INT_MAX;
        for (int v : a) {
            if (v > max1) {
                max3 = max2;
                max2 = max1;
                max1 = v;
            } else if (v > max2) {
                max3 = max2;
                max2 = v;
            } else if (v > max3) {
                max3 = v;
            }
            if (v < min1) {
                min2 = min1;
                min1 = v;
            } else if (v < min2) {
                min2 = v;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};




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




//Multiset solution
class Solution {
public:
    int maximumProduct(vector<int>& a) {
        multiset<int> max3;
        multiset<int> min2;
        for (int v : a) {
            max3.insert(v);
            if (max3.size() > 3) {
                max3.erase(max3.begin());
            }
            min2.insert(v);
            if (min2.size() > 2) {
                min2.erase(--min2.end());
            }
        }
        int a0 = *min2.begin();
        int a1 = *++min2.begin();
        int am3 = *max3.begin();
        int am2 = *++max3.begin();
        int am1 = *++++max3.begin();
        return max(a0 * a1 * am1, am3 * am2 * am1);
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
