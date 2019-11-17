//First solution
class Solution {
public:
    bool isValid(const string &s) {
        stack<char, vector<char>> st;
        for (char c: s) {
            if (c=='(') {
                st.push(')');
            } else if (c == '[') {
                st.push(']');
            } else if (c=='{') {
                st.push('}');
            } else {
                if (st.empty()) {
                    return false;
                }
                if (st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};


//Second solution
class Solution {
public:
    bool isValid(const string &s) {
        stack<char> st;  //here is the only difference compared to the first solution above
        for (char c: s) {
            if (c=='(') {
                st.push(')');
            } else if (c == '[') {
                st.push(']');
            } else if (c=='{') {
                st.push('}');
            } else {
                if (st.empty()) {
                    return false;
                }
                if (st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};


//Third solution
class Solution {
public:
    bool isValid(string s) {
        while (true) {
            if (s.empty()) {
                return true;
            }
            {
                size_t pos = s.find("()");
                if (pos != string::npos) { // found
                    s.erase(pos, 2);
                    continue;
                }
            }
            {
                size_t pos = s.find("[]");
                if (pos != string::npos) { // found
                    s.erase(pos, 2);
                    continue;
                }
            }
            {
                size_t pos = s.find("{}");
                if (pos != string::npos) { // found
                    s.erase(pos, 2);
                    continue;
                }
            }
            return false;
        }
    }
};
